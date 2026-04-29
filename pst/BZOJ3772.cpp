#include <bits/stdc++.h>
using namespace std;

int n, m, c, cnt;
int a[100005], b[100005];
int dfn[100005], dfo[100005], dep[100005], root[100005];
vector<int> G[100005];
vector<int> GG[100005];
int t[8000005], lc[8000005], rc[8000005];
int up[100005][20];

void dfs1(int x, int f){
	dfn[x] = ++cnt;
	dep[x] = dep[f]+1;
	up[x][0] = f;
	for (int i = 1; i <= 17; i++){
		up[x][i] = up[up[x][i-1]][i-1];
	}
	for (int v : G[x]){
		if (v == f) continue;
		dfs1(v, x);
	}
	dfo[x] = cnt;
}

int add(int x, int l, int r, int q){
	int nx = ++c;
	int mid = (l+r)>>1;
	lc[nx] = lc[x];
	rc[nx] = rc[x];
	t[nx] = t[x]+1;
	if (l == r) return nx;
	if (q <= mid){
		lc[nx] = add(lc[x], l, mid, q);
	} else {
		rc[nx] = add(rc[x], mid+1, r, q);
	}
	return nx;
}

int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 17; i >= 0; i--){
		if (dep[x]-(1<<i) >= dep[y]){
			x = up[x][i];
		}
	}
	if (x == y) return x;
	for (int i = 17; i >= 0; i--){
		if (up[x][i]!=up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}

int jump(int x, int father){
	for (int i = 17; i >= 0; i--){
		if (dep[x]-(1<<i) > dep[father]){
			x = up[x][i];
		}
	}
	return x;
}

int query(int x, int l, int r, int ql, int qr){
	if (ql <= l && qr >= r){
		return t[x];
	}
	int mid = (l+r)>>1;
	int s = 0;
	if (ql <= mid) s += query(lc[x], l, mid, ql, qr);
	if (qr > mid) s += query(rc[x], mid+1, r, ql, qr);
	return s;
}

int query(int x, int l, int r){
	return query(x, 1, n, l, r);
}

void answer(long long numerator){
	long long denom = 1LL*m*(m-1)/2;
	long long g = __gcd(numerator, denom);
	denom /= g;
	numerator /= g;
	cout << numerator << '/' << denom << '\n';
}

int main(){
	cin >> n >> m;
	for (int i = 1; i < n; i++){
		int x, y; cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs1(1, 1);
	for (int i = 1; i <= m; i++){
		cin >> a[i] >> b[i];
		GG[dfn[a[i]]].push_back(dfn[b[i]]);
		if (a[i] != b[i]) GG[dfn[b[i]]].push_back(dfn[a[i]]);
	}
	for (int i = 1; i <= n; i++){
		root[i] = root[i-1];
		for (int v : GG[i]){
			root[i] = add(root[i], 1, n, v);
		}
	}
	long long ans = 0;
	for (int i = 1; i <= m; i++){
		int cc = lca(a[i], b[i]);
		if (a[i] == b[i]){
			int larger = query(root[dfo[a[i]]], 1, n) - 
			query(root[dfo[a[i]]], dfn[a[i]]+1, dfo[a[i]]);
			int smaller= query(root[dfn[a[i]]-1], 1, n) -
			query(root[dfn[a[i]]-1], dfn[a[i]]+1, dfo[a[i]]);
			ans += larger-smaller-1;
		} else if (cc == a[i]){
			int tmp = jump(b[i], cc);
			int larger = query(root[dfo[b[i]]], 1, n)-
			query(root[dfo[b[i]]], dfn[tmp], dfo[tmp]);
			int smaller = query(root[dfn[b[i]]-1], 1, n)-
			query(root[dfn[b[i]]-1], dfn[tmp], dfo[tmp]);
			ans += larger-smaller-1;
		} else if (cc == b[i]){
			int tmp = jump(a[i], cc);
			int larger = query(root[dfo[a[i]]], 1, n)-
			query(root[dfo[a[i]]], dfn[tmp], dfo[tmp]);
			int smaller = query(root[dfn[a[i]]-1], 1, n)-
			query(root[dfn[a[i]]-1], dfn[tmp], dfo[tmp]);
			ans += larger-smaller-1;
		} else {
			int larger = query(root[dfo[a[i]]], dfn[b[i]], dfo[b[i]]);
			int smaller = query(root[dfn[a[i]]-1], dfn[b[i]], dfo[b[i]]);
			ans += larger-smaller-1;
		}
	}
	answer(ans);

	return 0;
}


