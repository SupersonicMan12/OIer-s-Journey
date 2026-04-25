#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int INV = 499122177;
int n, q; 
long long t[400005], tt[400005];
long long lz[400005];

int push_down(int x, int l, int r){
	int mid = (l+r)>>1;
	if (lz[x]){
		long long v = lz[x];
		(tt[x<<1] += 1LL*v*v%MOD*(mid-l+1)%MOD) %= MOD;
		(tt[x<<1] += 2LL*v*t[x<<1]%MOD) %= MOD;
		(t[x<<1] += 1LL*v*(mid-l+1)%MOD) %= MOD;
		(lz[x<<1] += v)%=MOD;
		(tt[x<<1|1] += 1LL*v*v%MOD*(r-mid)%MOD)%=MOD;
		(tt[x<<1|1] += 2LL*v*t[x<<1|1]%MOD)%=MOD;
		(t[x<<1|1] += 1LL*v*(r-mid)%MOD)%=MOD;
		(lz[x<<1|1] += v)%=MOD;
		lz[x] = 0;
	}
	return mid;
}

void upd(int x, int l, int r, int ql, int qr, int v){
	if (ql <= l && qr >= r){
		(tt[x] += 1LL*v*v%MOD*(r-l+1)%MOD)%=MOD;
		(tt[x] += 2LL*v*t[x]%MOD)%=MOD;
		(t[x] += 1LL*v*(r-l+1)%MOD)%=MOD;
		(lz[x] += v) %= MOD;
		return;
	}
	int mid = push_down(x, l, r);
	if (ql <= mid) upd(x<<1, l, mid, ql, qr, v);
	if (qr > mid) upd(x<<1|1, mid+1, r, ql, qr, v);
	t[x] = (t[x<<1]+t[x<<1|1])%MOD;
	tt[x] = (tt[x<<1]+tt[x<<1|1])%MOD;
}

long long qsum(int x, int l, int r, int ql, int qr){
	if (ql <= l && qr >= r){
		return t[x];
	}
	long long ans = 0;
	int mid = push_down(x, l, r);
	if (ql <= mid) (ans += qsum(x<<1, l, mid, ql, qr)) %= MOD;
	if (qr > mid) (ans += qsum(x<<1|1, mid+1, r, ql, qr)) %= MOD;
	return ans;
}

long long qsquare(int x, int l, int r, int ql, int qr){
	if (ql <= l && qr >= r){
		return tt[x];
	}
	long long ans = 0;
	int mid = push_down(x, l, r);
	if (ql <= mid) (ans += qsquare(x<<1, l, mid, ql, qr)) %= MOD;
	if (qr > mid) (ans += qsquare(x<<1|1, mid+1, r, ql, qr)) %= MOD;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= q; i++){
		int l, r, a; cin >> l >> r >> a;
		upd(1, 1, n, l, r, a);
		long long s = qsum(1, 1, n, l, r);
		long long ss = qsquare(1, 1, n, l, r);
		long long ans = (s*s%MOD-ss+MOD)%MOD*INV%MOD;
		cout << ans << '\n';
	}

	return 0;
}