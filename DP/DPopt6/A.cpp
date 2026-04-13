#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int opt[5005][5005];

int n;
int a[5005];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] += a[i-1];
		opt[i][i+1] = i;
		dp[i][i] = 0;
		dp[i-1][i] = a[i]-a[i-2];
	}
	for (int len = 3; len <= n; len++){
		for (int l = 1; l + len-1 <= n; l++){
			int r = l+len-1;
			int best = 0;
			int curr = ((1<<31)-1);
			for (int k = opt[l][r-1]; k <= opt[l+1][r]; k++){
				if (k < r && curr >= dp[l][k]+dp[k+1][r]){
					curr = dp[l][k]+dp[k+1][r];
					best = k;
				}
			}
			dp[l][r] = curr + a[r]-a[l-1];
			opt[l][r] = best;
		}
	}
	cout << dp[1][n] << '\n';

	return 0;
}