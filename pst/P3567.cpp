#include <bits/stdc++.h>
using namespace std;

int n, m, c;
int a[500005];
int t[11000004], lc[11000004], rc[11000004];
int root[500005];

void build(int &x, int l, int r){
	if (!x) x = ++c;
	if (l == r) return;
	int mid = (l+r)>>1;
	build(lc[x], l, mid);
	build(rc[x], mid+1, r);
}

int add(int x, int l, int r, int q){
	if (l==r){
		t[++c] = t[x]+1;
		return c;
	}
	int mid = (l+r)>>1;
	int nx = ++c;
	if (q <= mid){
		lc[nx] = add(lc[x], l, mid, q);
		rc[nx] = rc[x];
	} else {
		lc[nx] = lc[x];
		rc[nx] = add(rc[x], mid+1, r, q);
	}
	t[nx] = t[lc[nx]] + t[rc[nx]];
	return nx;
}

int query(int x, int y, int l, int r, int k){
	if (l == r){
		return l;
	}
	int mid = (l+r)>>1;
	if (t[lc[y]]-t[lc[x]] >= k) return query(lc[x], lc[y], l, mid, k);
	if (t[rc[y]]-t[rc[x]] >= k) return query(rc[x], rc[y], mid+1, r, k);
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(root[0], 1, n);
	for (int i = 1; i <= n; i++){
		root[i] = add(root[i-1], 1, n, a[i]);
	}
	for (int i = 1; i <= m; i++){
		int l, r; cin >> l >> r;
		cout << query(root[l-1], root[r], 1, n, (r-l+3)/2) << '\n'; 
	}

	return 0;
}



