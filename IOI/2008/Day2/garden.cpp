#include <bits/stdc++.h>
using namespace std;

int n, MOD;
// number of ways to complete i spots
// with worst prefix being -j, and best prefix being +k
int dp[1000005][3][3];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> MOD;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 3; k++){
				// consider the prefix [-j, +k]
				// if a +1 is provided,
				if (k <= 1){
					if (j > 0) 	(dp[i][j-1][k+1] += dp[i-1][j][k])%=MOD;
					else 		(dp[i][j][k+1] += dp[i-1][j][k]) %= MOD;
				}
				// if a -1 is provided,
				if (j <= 1){
					if (k > 0) 	(dp[i][j+1][k-1] += dp[i-1][j][k])%=MOD;
					else 		(dp[i][j+1][k] += dp[i-1][j][k])%=MOD;
				}
			}
		}
	}
	// for (int j = 0; j < 3; j++){
	// 	for (int k = 0; k < 3; k++)
	// 		cout << dp[n][j][k] << ' ';
	// 	cout << '\n';
	// }
	string s; cin >> s; s = "$"+s;
	int p = 0, l = 0;
	long long ans = 1;
	for (int i = 1; i <= n; i++){
		if (s[i]=='L') {
			l++;
			if (p) p--;
		} else {
			int cl = l+1;
			int cp = p?p-1:0;
			for (int ll = 0; ll <= 2-cl; ll++){
				for (int pp = 0; pp <= 2-cp; pp++){
					ans = (ans + dp[n-i][ll][pp]) % MOD;
				}
			}
			p++;
			if (l) l--;
		}
	}
	cout << ans << endl;
	return 0;
}


