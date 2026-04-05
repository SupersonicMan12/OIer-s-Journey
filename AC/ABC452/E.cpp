#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m;
int a[500005], b[500005];
int p[500005];

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		(p[i]=p[i-1]+a[i]) %= MOD;
	}
	for (int i = 1; i <= m; i++) cin >> b[i];
	long long ans = 0;
	for (int j = 1; j <= m; j++){
		long long internal = 0;
		for (int q = 1; q < n/j; q++){
			(internal += 1LL*q*(p[(q+1)*j-1]-p[q*j-1]+MOD)%MOD) %= MOD;
		}
		int q = n/j;
		(internal += 1LL*q*(p[n]-p[q*j-1]+MOD)%MOD) %= MOD;
		internal = (1LL * internal * j % MOD * b[j] % MOD);
		ans = (ans+internal)%MOD;
	}
	long long bans = 0, cans = 0;
	for (int i = 1; i <= n; i++){
		(bans += 1LL*i*a[i]%MOD) %= MOD;
	}
	for (int i = 1; i <= m; i++){
		(cans += b[i]) %= MOD;
	}
	ans = (bans*cans % MOD - ans + MOD) % MOD;
	cout << ans << '\n';

	return 0; 
}