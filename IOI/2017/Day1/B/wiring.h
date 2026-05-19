#include <bits/stdc++.h>
using namespace std;

long long dp[505][505];

void mn(long long &x, long long y){
	if (x > y) x = y;
}

long long min_total_length(vector<int> r, vector<int> b){
	vector<int> R; vector<int> B; 
	R.push_back(0); B.push_back(0);
	int n = r.size();
	int m = b.size();
	for (int i = 0; i < n; i++){
		R.push_back(r[i]);
	}
	for (int i = 0; i < m; i++){
		B.push_back(b[i]);
	}

	if (n <= 500 && m <= 500){
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				long long s = 0;
				for (int k = j-1; k >= 0; k--){
					s += abs(R[i]-B[k+1]);
					mn(dp[i][j], dp[i-1][k]+s);
				}
				s = 0;
				for (int k = i-1; k >= 0; k--){
					s += abs(R[k+1]-B[j]);
					mn(dp[i][j], dp[k][j-1]+s);
				}
			}
		}
	} else if (B[1] > R[n]){
		long long ans = 0;
		if (n < m){
			for (int i = 1; i <= n; i++){
				ans += B[i]-R[i];
			}
			for (int i = n+1; i <= m; i++){
				ans += B[i]-R[n];
			}
		} else {
			for (int i = 1; i <= m; i++){
				ans += B[i]-R[i];
			}
			for (int i = m+1; i <= n; i++){
				ans += B[1]-R[i];
			}
		}
		return ans;
	}
	

	
	return dp[n][m];
}
