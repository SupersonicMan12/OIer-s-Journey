#include <bits/stdc++.h>
using namespace std;

int n, q, c;
int a[1000005], root[1000005];
int t[40000005], lc[40000005], rc[40000005];

void build(int &x, int l, int r){
	if (!x) x = ++c;
	if (l==r){
		t[x] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(lc[x], l, mid);
	build(rc[x], mid+1, r);
}

int update(int x, int l, int r, int q, int v){
	if (l == r){
		t[++c] = v;
		return c;
	}
	int mid = (l+r)>>1;
	int nx = ++c;
	if (q <= mid){
		lc[nx] = update(lc[x], l, mid, q, v);
		rc[nx] = rc[x];
	} else {
		lc[nx] = lc[x];
		rc[nx] = update(rc[x], mid+1, r, q, v);
	}
	// no need for maintenance
	return nx;
}

int qry(int x, int l, int r, int q){
	if (l == r) return t[x];
	int mid = (l+r)>>1;
	if (q <= mid) return qry(lc[x], l, mid, q);
	else return qry(rc[x], mid+1, r, q);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(root[0], 1, n);
	for (int i = 1; i <= q; i++){
		int v, op, p;
		cin >> v >> op >> p;
		if (op == 1){
			int f; cin >> f;
			root[i] = update(root[v], 1, n, p, f);
		} else {
			root[i] = root[v];
			cout << qry(root[i], 1, n, p) << '\n';
		}
	}
	return 0;
}


