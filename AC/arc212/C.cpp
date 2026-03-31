/*
With this, the rest is easy: we have (k+M-1) C (2M-1) * ((N-k)/2+M-1) C (M-1) * 2^M
*/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

long long fact[20000005];
long long inv[20000005];
long long ifact[20000005];

// moral of the story: combination always look for edge cases!
long long comb(int x, int y){
	if (x < y) return 0LL;
	return 1LL*fact[x]*ifact[y]%MOD*ifact[x-y]%MOD;
}

long long pow(long long x, int n){
	long long ans = 1;
	while (n){
		if (n&1) ans = (ans*x)%MOD;
		x = (x*x)%MOD;
		n >>= 1;
	}
	return ans;
}

int main(){
	int n, m; cin >> n >> m;
	fact[0] = fact[1] = 1;
    inv[1] = 1;
    ifact[0] = ifact[1] = 1;
    for (int i = 2; i <= n+m; i++) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        ifact[i] = ifact[i-1] * inv[i] % MOD;
    }

	long long ans = 0;
	for (int k = n; k >= 0; k -= 2){
		// n-k is even.
		long long tmp = comb(k+m-1, 2*m-1) * comb((n-k)/2+m-1, m-1) % MOD;
		ans = (ans + tmp) % MOD;
	}
	ans = ans * pow(2LL, m) % MOD;
	cout << ans << '\n';

	return 0;
}