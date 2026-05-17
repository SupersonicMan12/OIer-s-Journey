#include <bits/stdc++.h>
using namespace std;

long long INF = 0x3f3f3f3f3f3f3f3f;
long long dp[66000][16];

void mx(long long &x, long long y){
	if (y < x) x = y;
}

long long plan_roller_coaster(vector<int> s, vector<int> t){
	int n = s.size();
	if (n <= 16){
		// bitmask DP
		memset(dp, 0x3f, sizeof(dp));
		int N = (1<<n)-1;
		for (int i = 0; i < n; i++) dp[1<<i][i] = 0;
		for (int M = 0; M < N; M++){
			for (int curr = 0; curr < n; curr++){
				if (dp[M][curr] == INF) continue;
				for (int nxt = 0; nxt < n; nxt++){
					if ((M>>nxt)&1) continue;
					mx(dp[M^(1<<nxt)][nxt], dp[M][curr]+max(t[curr]-s[nxt],0));
				}
			}
		}
		long long ans = INF;
		for (int i = 0; i < n; i++){
			if (dp[N][i]<ans)ans=dp[N][i];
		}
		return ans;
	} else {
		return 0;
	}
}