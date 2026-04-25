#include <bits/stdc++.h>
using namespace std;

int n, q, c, r;
int a[200005];
int root[200005];
long long t[8000005]; 
int lc[8000005], rc[8000005];

void build(int &x, int l, int r){
	if (!x) x = ++c;
	if (l==r) {t[x] = a[l]; return;}
	int mid = (l+r)>>1;
	build(lc[x], l, mid);
	build(rc[x], mid+1, r);
	t[x] = t[lc[x]]+t[rc[x]];
}

long long qry(int x, int l, int r, int ql, int qr){
	if (!x) return 0;
	if (ql <= l && qr >= r){
		return t[x];
	}
	int mid = (l+r)>>1;
	long long ans = 0;
	if (ql <= mid) 	ans += qry(lc[x], l, mid, ql, qr);
	if (qr > mid) 	ans += qry(rc[x], mid+1, r, ql, qr);
	return ans;
}

int update(int x, int l, int r, int q, int v){
	if (l == r){
		t[++c] = v;
		return c; 
	}
	int mid = (l+r)>>1;
	int nx = ++c;
	if (q <= mid) {
		lc[nx] = update(lc[x], l, mid, q, v);
		rc[nx] = rc[x];
	} else {
		rc[nx] = update(rc[x], mid+1, r, q, v);
		lc[nx] = lc[x];
	}
	t[nx] = t[lc[nx]] + t[rc[nx]];
	return nx;
}

int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(root[1],1,n);
	r = 1;
	for (int i = 1; i <= q; i++){
		int op, k; cin >> op >> k;
		if (op == 1){
			int a, x; cin >> a >> x;
			root[k] = update(root[k], 1, n, a, x);
		} else if (op == 2){
			int a, b; cin >> a >> b;
			cout << qry(root[k], 1, n, a, b) << '\n';
		} else {
			// duplicate
			root[++r] = root[k];
		}
	}

	return 0;
}




