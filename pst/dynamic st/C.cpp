// problem: online append + query max of last L, for 200000 queries, mod D

#include <bits/stdc++.h>
using namespace std;

int m,d;
int t[800005];

void upd(int x, int l, int r, int q, int v){
	if (l == r){
		t[x] = v;
		return;
	}
	int mid = (l+r)>>1;
	if (q <= mid) upd(x<<1, l, mid, q, v);
	else upd(x<<1|1, mid+1, r, q, v);
	t[x] = max(t[x<<1], t[x<<1|1]);
}

int qry(int x, int l, int r, int ql, int qr){
	if (ql <= l && qr >= r){
		return t[x];
	}
	int mid = (l+r)>>1;
	int ans = 0;
	if (ql <= mid) ans = max(ans, qry(x<<1, l, mid, ql, qr));
	if (qr > mid) ans = max(ans, qry(x<<1|1, mid+1, r, ql, qr));
	return ans;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> d;
	int t = 0, curr = 0;
	for (int i = 1; i <= m; i++){
		char op; cin >> op;
		if (op == 'A'){
			long long n; cin >> n;
			upd(1, 1, m, ++curr, (n+t)%d);
		} else {
			int n; cin >> n;
			t = qry(1, 1, m, curr-n+1, curr);
			cout << t << '\n';
		}
	}
	return 0;
}