#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;
int n, m, useless;
vector<int> G[N];
long long t[4*N], lz[4*N];

void push(int x){
	if (lz[x]!=1){
		t[x<<1] = t[x<<1]*lz[x]%MOD;
		lz[x<<1] = lz[x<<1]*lz[x]%MOD;
		t[x<<1|1] = t[x<<1|1]*lz[x]%MOD;
		lz[x<<1|1] = lz[x<<1|1]*lz[x]%MOD;
		lz[x] = 1;
	}
}

void upd(int x, int l, int r, int ql, int qr, long long v){
	if (ql > r || qr < l) return;
	if (l >= ql && r <= qr){
		t[x] = t[x]*v%MOD;
		lz[x] = lz[x]*v%MOD;
		return;
	}
	int mid = (l+r)>>1; push(x); 
	upd(x<<1, l, mid, ql, qr, v);
	upd(x<<1|1, mid+1, r, ql, qr, v);
	t[x] = (t[x<<1]+t[x<<1|1])%MOD;
}

void point(int x, int l, int r, int q, int v){
	if (l == r) {
		t[x] = v;
		return;
	}
	int mid = (l+r)>>1;
	push(x);
	if (q <= mid) point(x<<1, l, mid, q, v);
	else point(x<<1|1, mid+1, r, q, v);
	t[x] = (t[x<<1]+t[x<<1|1])%MOD;
}

long long qry(int x, int l, int r, int ql, int qr){
	if (ql > r || qr < l) return 0;
	if (l >= ql && r <= qr) return t[x];
	push(x); int mid = (l+r)>>1;
	return (qry(x<<1, l, mid, ql, qr)+qry(x<<1|1, mid+1, r, ql, qr))%MOD;
}

long long pw(long long b,long long e){
    long long r=1;b%=MOD;for(;e;e>>=1){if(e&1)r=r*b%MOD;b=b*b%MOD;}return r;
}

int main(){
	cin >> n >> m;
	fill(lz, lz+4*N, 1);
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y; 
		if (x >= y) useless++;
		else G[y-1].push_back(x);
	}
	point(1,0,n-1,0,1);
	for (int j = 1; j < n; j++){
		// change those that have extra 2
		for (int l: G[j-1]) upd(1,0,n-1,0,l-1,2);
		// update dp itself
		point(1,0,n-1,j,(MOD-qry(1,0,n-1,0,j-1))%MOD);
	}
	for (int l: G[n-1]) upd(1,0,n-1,0,l-1,2);
	cout << qry(1,0,n-1,0,n-1)*pw(2,useless)%MOD << '\n';

	return 0;
}



