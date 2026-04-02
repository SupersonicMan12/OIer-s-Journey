// Raucous Rockers P2736, extended to higher inputs in cdc.cpp

#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int l[25];
// disk i, time t
int dp[25][25];

int main(){
	cin >> n >> t >> m;
	for (int i = 1; i <= n; i++) cin >> l[i];
	for (int i = 1; i <= m; i++){
		for (int j = 0; j <= t; j++){
			dp[i][j] = -100000;
		}
	}
	dp[1][0] = 0;
	for (int d = 1; d <= n; d++){
		for (int i = m; i >= 1; i--){
			for (int j = t; j >= 0; j--){
				if (dp[i][j]<0) continue;
				if (j + l[d] <= t)
				dp[i][j+l[d]] = max(dp[i][j+l[d]], dp[i][j]+1);
				dp[i+1][l[d]] = max(dp[i+1][l[d]], dp[i][j]+1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++){
		for (int j = 0; j <= t; j++){
			ans = max(dp[i][j], ans);
		}
	}
	cout << ans << '\n';

	return 0;
}

