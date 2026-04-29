// problem: given n strings, for m online queries of prefix+suffix
// find the number of strings that have both this prefix+suffix

// total lengths <= 2e6, n <= 2000, m <= 100000;

#include <bits/stdc++.h>
using namespace std;

int n, m, c1, c2, c;
int pref[2000005][26];
int posf[2000005][26];
int dfn1[2000005], dfo1[2000005];
int dfn2[2000005], dfo2[2000005];
int root[2000005];
int t[49000], lc[49000], rc[49000];
vector<int> G[2000005];
int p[2][2005];

void dfs1(int x){
	dfn1[x] = ++c1;
	for (int i = 0; i < 26; i++){
		if (pref[x][i]) dfs1(pref[x][i]);
	}
	dfo1[x] = c1;
}

void dfs2(int x){
	dfn2[x] = ++c2;
	for (int i = 0; i < 26; i++){
		if (posf[x][i]) dfs2(posf[x][i]);
	}
	dfo2[x] = c2;
}

int add(int x, int l, int r, int q){
	int nx = ++c;
	int mid = (l+r)>>1;
	t[nx] = t[x]+1;
	lc[nx] = lc[x];
	rc[nx] = rc[x];
	if (l == r) return nx;
	if (q <= mid) lc[nx]=add(lc[x], l, mid, q);
	else 		rc[nx]=add(rc[x], mid+1, r, q);
	return nx;
}

int query(int x, int l, int r, int ql, int qr){
	if (l >= ql && r <= qr) return t[x];
	int mid = (l+r)>>1;
	int ans = 0;
	if (ql <= mid) ans += query(lc[x], l, mid, ql, qr);
	if (qr > mid) ans += query(rc[x], mid+1, r, ql, qr);
	return ans;
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		int l = s.length();
		int p1 = 0;
		for (int j = 0; j < l; j++){
			int idx = s[j]-'a';
			if (!pref[p1][idx]){
				pref[p1][idx] = ++c1;
			}
			p1 = pref[p1][idx];
		}
		int p2 = 0;
		for (int j = l-1; j >= 0; j--){
			int idx = s[j]-'a';
			if (!posf[p2][idx]){
				posf[p2][idx] = ++c2;
			}
			p2 = posf[p2][idx];
		}
		p[0][i] = p1;
		p[1][i] = p2;
	}
	c1 = 0;
	dfs1(0);
	c2 = 0;
	dfs2(0);
	for (int i = 1; i <= n; i++){
		G[dfn1[p[0][i]]].push_back(dfn2[p[1][i]]);
	}
	for (int i = 1; i <= c1; i++){
		root[i] = root[i-1];
		for (int v : G[i]){
			root[i] = add(root[i], 1, c2, v);
		}
	}
	cin >> m;
	int last = 0;
	for (int i = 1; i <= m; i++){
		string s, t; cin >> s >> t;
		last %= 26;
		int p1 = 0;
		bool bad = 0;
		for (char ch : s){
			if (!pref[p1][(ch-'a'+last)%26]){
				bad = 1;
				break;
			}
			p1 = pref[p1][(ch-'a'+last)%26];
		}
		int p2 = 0;
		int T = t.length();
		for (int j = T-1; j >= 0; j--){
			char ch = t[j];
			if (!posf[p2][(ch-'a'+last)%26]){
				bad = 1;
				break;
			}
			p2 = posf[p2][(ch-'a'+last)%26];
		}
		if (bad){
			cout << 0 << '\n';
			last = 0;
			continue;
		}
		last = query(root[dfo1[p1]], 1, c2, dfn2[p2], dfo2[p2]);
		last -= query(root[dfn1[p1]-1], 1, c2, dfn2[p2], dfo2[p2]);
		cout << last << '\n';
	}

	return 0;
}


