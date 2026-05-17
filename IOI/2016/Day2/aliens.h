#pragma once

#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;

void mn(long long &x,long long y){
	if (y < x) x = y;
}

long long take_photos(int n, int m, int k, vector<int> r, vector<int> c){
	pair<int,int> P[50005];
	for (int i = 1; i <= n; i++){	
		P[i].first = min(r[i-1], c[i-1]);
		P[i].second = max(r[i-1], c[i-1]);
	}
	sort(P+1, P+n+1, [](auto a, auto b){
		if (a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	});
	pair<int,int> PP[50005];
	PP[0].second = -1;
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (P[i].second <= PP[cnt].second) continue;
		PP[++cnt] = P[i];
		// cout << P[i].first << P[i].second << '\n';
	}
	vector<vector<long long>> dp(cnt+1, vector<long long>(k+1, INF));
	dp[0][0] = 0;
	for (int t = 0; t < cnt; t++){
		for (int j = 1; j <= k; j++){
			if (dp[t][j-1] == INF) continue;
			for (int i = t+1; i <= cnt; i++){
				long long d = (PP[i].second-PP[t+1].first+1);
				long long cost = d*d;
				if (t > 0){
					long long ov = PP[t].second - PP[t+1].first + 1;
					if (ov > 0) cost -= ov*ov;
				}
				mn(dp[i][j], dp[t][j-1]+cost);
			}
		}
	}
	long long ans = INF;
	for (int i = 1; i <= k; i++){
		mn(ans, dp[cnt][i]);
	}
	return ans;
}

