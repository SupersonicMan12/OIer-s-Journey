#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int t, n, k;
int a[500005];
bool done[500005];
int c[500005];
int fact[500005];

int pow(int x, int n){
	long long r = 1;
	while (n){
		if (n & 1) r = r*x%MOD;
		x = 1LL*x*x%MOD;
		n >>= 1;
	}
	return (int)r;
}

void solve(){
	long long ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) done[i] = 0;
	int best = 0;
	for (int i = 1; i <= k; i++){
		cin >> a[i];
		if (a[i] < best){
			(ans += 1LL*fact[n-k]*pow(2,a[i]-1)%MOD)%=MOD;
		}
		best = max(best, a[i]);
		done[a[i]] = 1;
	}
	int cnt = 0;
	for (int i = n; i >= 1; i--){
		if (!done[i]){
			c[i] = ++cnt;
		}
	}
	for (int i = 1; i <= n; i++){
		if (done[i]) continue;
		if (i <= best){
			(ans += 1LL*fact[n-k]*pow(2, i-1)%MOD) %= MOD;
		} else {
			(ans += 1LL*(c[i]-1)*fact[n-k]%MOD*pow(c[i], MOD-2)%MOD*pow(2, i-1)%MOD) %= MOD;
		}
	}
	cout << ans << '\n';
}

int main(){
	fact[0] = 1;
	for (int i = 1; i <= 500000; i++){
		fact[i] = 1LL*fact[i-1]*i%MOD;
	}
	cin >> t; while (t--) solve();
	return 0;
}