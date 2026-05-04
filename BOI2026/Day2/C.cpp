#include <bits/stdc++.h>
using namespace std;
int n,q,c;
int x[200005];
pair<int,int> s[200005];
int a[200005], b[200005];
// 
int lhs[200005], rhs[200005];
bool lt[200005], rt[200005];
int bad[200005];
bool streaklhs[200005],streakrhs[200005];

int root[200005];
int t[8000005], lc[8000005], rc[8000005];

int add(int x, int l, int r, int q){
	int nx = ++c;
	t[nx] = t[x]+1;
	lc[nx] = lc[x];
	rc[nx] = rc[x];
	if (l == r) return nx;
	int mid = (l+r)>>1;
	if (q <= mid) lc[nx] = add(lc[x], l, mid, q);
	else 		rc[nx] = add(rc[x], mid+1, r, q);
	return nx;
}

int qry(int x, int l, int r, int ql, int qr){
	if (ql <= l && qr >= r) return t[x];
	int ans = 0;
	int mid = (l+r)>>1;
	if (ql <= mid) ans += qry(lc[x], l, mid, ql, qr);
	if (qr > mid) ans += qry(rc[x], mid+1, r, ql, qr);
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		s[i] = {x[i],i};
	}
	// discretize to 1...n;
	sort(s+1,s+n+1);
	for (int i = 1; i <= n; i++){
		x[s[i].second] = i;
	}
	for (int i = 1; i <= n; i++){
		bad[i] = bad[i-1]+(x[i]<x[i-1]);
	}

	int curr = 0;
	streaklhs[0] = 1;
	for (int i = 1; i <= n; i++){
		lt[x[i]] = 1;
		while (lt[curr+1]) curr++;
		lhs[i] = curr;
		streaklhs[i] = (streaklhs[i-1]&&(lhs[i]==i));
	}

	curr = n+1;
	streakrhs[n+1]=1;
	for (int i = n; i >= 1; i--){
		rt[x[i]] = 1;
		while (rt[curr-1]) curr--;
		rhs[i] = curr;
		streakrhs[i] = (streakrhs[i+1]&&(rhs[i]==i));
	}
	// for (int i = 1; i <= n; i++) cout << streaklhs[i];
	// for (int i = 1; i <= n; i++) cout << streakrhs[i];
	
	bool flag = 1;
	for (int i = 1; i <= q; i++){
		cin >> a[i] >> b[i];	
		if (a[i] + b[i] > n) flag = 0;
		b[i] = n-b[i]+1;
	}
	// subtasks 1, 3
	if (flag){
		for (int i = 1; i <= q; i++){
			if (lhs[a[i]]==a[i] && rhs[b[i]]==b[i] && bad[b[i]]==bad[a[i]]){
				int ans = 0;
				if (!streaklhs[a[i]]) ans++;
				if (!streakrhs[b[i]]) ans++;
				cout << ans << '\n';
			} else {
				cout << -1 << '\n';
			}
		}
	} else {
		for (int i = 1; i <= n; i++){
			root[i] = add(root[i-1], 1, n, x[i]);
		}
		for (int i = 1; i <= q; i++){
			if (a[i] >= b[i]){
				int l = qry(root[b[i]-1], 1, n, b[i], n);
				int k = qry(root[n], 1, n, 1, a[i]) - qry(root[a[i]], 1, n, 1, a[i]);
				int window = (a[i]-b[i]+1);
				int kw = (k+window-1)/window;
				int lw = (l+window-1)/window;
				int ans = min(max(1+2*lw,2*kw), max(1+2*kw, 2*lw));
				cout << ans << '\n';
			} else {
				if (lhs[a[i]]==a[i] && rhs[b[i]]==b[i] && bad[b[i]]==bad[a[i]]){
					int ans = 0;
					if (!streaklhs[a[i]]) ans++;
					if (!streakrhs[b[i]]) ans++;
					cout << ans << '\n';
				} else {
					cout << -1 << '\n';
				}
			}
		}
	}
	return 0;
}


