#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n, k;
long long a[20005];

int main(){
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	long long max = (1LL<<k);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			if (i==j) (ans += max)%=MOD;
			else if (a[i]==a[j]) (ans += (max<<1))%=MOD;
			else (ans += (1LL<<(k-__builtin_popcountll(a[j]-a[i])))%MOD) %= MOD;
		}
	}
	cout << ans << '\n';
	return 0;
}
// builtin_popcount etc.


