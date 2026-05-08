// sqrt() divide and conquer
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n, B;
int dp[100005];
vector<tuple<int,int,int>> rm[100005];
int cong[352][352];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	B = sqrt(n);
	dp[1] = 1;
	for (int i = 1; i <= n; i++){
		int x, d; cin >> d >> x;
		// add the x >= B category
		for (auto [u,v,w]: rm[i]){
			cong[u][v] = (cong[u][v]-w+MOD)%MOD;
		}
		for (int k = 1; k <= B; k++){
			(dp[i] = dp[i]+cong[k][i%k]) %= MOD;
		}
		if (d == 0) continue; // skipped
		if (d > B){
			// brute force
			int y = i;
			for (int j = 1; j <= x; j++){
				y += d;
				if (y > n) break;
				dp[y] = (dp[y]+dp[i])%MOD;
			}
		} else {
			cong[d][i%d] = (cong[d][i%d]+dp[i])%MOD;
			// store in corresponding
			long long fin = i+1LL*x*d+1;
			if (fin <= n){
				rm[fin].push_back({d,i%d,dp[i]});
			} 
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + dp[i]);
	}
	ans %= MOD;
	cout << ans << endl;
	return 0;
}



