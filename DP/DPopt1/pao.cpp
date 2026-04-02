#include <bits/stdc++.h>
using namespace std;

const int MOD = 9999973;
// row, zeros, ones
int dp[105][105][105];

int n, m;

int main(){
	cin >> n >> m;
	if (n > m) swap(n, m);
	dp[0][n][0] = 1;
	for (int row = 0; row < m; row++){
		for (int a = 0; a <= n; a++){
			for (int b = 0; b+a <= n; b++){
				if (a>=2)
				(dp[row+1][a-2][b+2] += 1LL*a*(a-1)/2*dp[row][a][b]%MOD) %= MOD;
				if (b>=2)
				(dp[row+1][a][b-2] += 1LL*b*(b-1)/2*dp[row][a][b]%MOD) %= MOD;
				if (a>=1 && b>=1)
				(dp[row+1][a-1][b] += 1LL*a*b*dp[row][a][b]%MOD) %= MOD;
				if (a>=1)
				(dp[row+1][a-1][b+1] += 1LL*a*dp[row][a][b]%MOD) %= MOD;
				if (b>=1)
				(dp[row+1][a][b-1] += 1LL*b*dp[row][a][b]%MOD) %= MOD;
				dp[row+1][a][b] += dp[row][a][b];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j + i <= n; j++){
			(ans += dp[m][i][j]) %= MOD;
		}
	}
	cout << ans << '\n';
	return 0;
}