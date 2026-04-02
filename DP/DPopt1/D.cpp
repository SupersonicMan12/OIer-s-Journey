#include <bits/stdc++.h>
using namespace std;

int n, k, a[10005];
int dp[10005][505];

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i][0] = 1;
	}
	for (int i = 1; i < n; i++){
		for (int m = i+1; m <= n; m++){
			int diff = a[m]-a[i];
			if (diff >= 0){
				for (int j = 0; j <= k; j++){
					dp[m][j] = max(dp[i][j]+1, dp[m][j]);
				}
			} else {
				for (int j = 0; j+diff <= k; j++){
					dp[m][j-diff] = max(dp[i][j]+1, dp[m][j+diff]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= k; j++){
			ans = max(ans, dp[i][j]);
		}
	}
	
	cout << ans << '\n';

	return 0;
}