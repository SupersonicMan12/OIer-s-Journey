#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;

// maxNodes = 6e6
int n, q, c, root;
int lc[6000000], rc[6000000];
int t[6000000], lz[6000000];

int push_down(int x, int l, int r){
	int mid = (l+r)>>1;
	if (!lz[x]) return mid;
	if (!lc[x]) lc[x] = ++c;
	if (!rc[x]) rc[x] = ++c;
	lz[lc[x]] += lz[x];
	lz[rc[x]] += lz[x];
	t[lc[x]] += lz[x];
	t[rc[x]] += lz[x];
	lz[x] = 0;
	return mid;
}

void add(int &x, int l, int r, int ql, int qr, int v){
	if (!x) x = ++c;
	if (l >= ql && r <= qr){
		lz[x]+=v;
		t[x]+=v;
		return;
	}
	int mid = push_down(x, l, r);
	if (ql <= mid) 	add(lc[x], l, mid, ql, qr, v);
	if (qr > mid) 	add(rc[x], mid+1, r, ql, qr, v);
	t[x] = min(t[lc[x]], t[rc[x]]);
}

int qry(int x, int l, int r, int ql, int qr){
	if (!x) return 0;
	if (l >= ql && r <= qr){
		return t[x];
	}
	int ans = INF;
	int mid = push_down(x, l, r);
	if (ql <= mid) 	ans = min(ans, qry(lc[x], l, mid, ql, qr));
	if (qr > mid) 	ans = min(ans, qry(rc[x], mid+1, r, ql, qr));
	return ans;
}

int main(){
	cin >> n >> q;
	for (int i = 1; i <= q; i++){
		int op, l, r;
		cin >> op >> l >> r;
		if (op==1){
			int v; cin >> v;
			add(root,1,n,l,r,v);
		} else {
			cout << qry(root,1,n,l,r) << '\n';
		}
	}
	return 0;
}