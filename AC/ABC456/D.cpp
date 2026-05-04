#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n; string s;
long long dp[3];

int main(){
	cin >> s;
	n = s.length();
	s = "#"+s;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		int me = s[i]-'a';
		long long add = 1;
		for (int j = 0; j < 3; j++){
			if (me == j) continue;
			(add += dp[j]) %= MOD;
		}
		(dp[me] += add) %= MOD;
		(ans += add) %=MOD;
	}
	cout << ans << '\n';
	return 0;
}