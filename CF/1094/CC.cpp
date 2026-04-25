#include <bits/stdc++.h>
using namespace std;

const int NINF = -1e9;
int t, n;
int a[5005];
// best for ending at i with median j
int dp[5005][5005];

void solve(){
	cin >> n;
	set<int> S;
	map<int,int> M;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		S.insert(a[i]);
	}
	int cnt = 0;
	for (auto u : S){
		M[u] = ++cnt;
	}
	//discretize into [1, cnt]
	for (int i =1 ; i <= n; i++){
		a[i] = M[a[i]];
	}

	for (int i = 0; i <= n; i++)
    for (int j = 1; j <= cnt; j++)
	dp[i][j] = NINF;

	for (int i = 1; i <= cnt; i++){
		dp[0][i] = 0;
	}
	// fixed for this med
	for (int med = 1; med <= cnt; med++){
		for (int i = 0; i < n; i++){
			// push dp[i][med]
			int less = 0, great = 0;
			bool appear = 0;
			if (a[i+1] < med) less++;
			if (a[i+1] > med) great++;
			if (a[i+1] == med) dp[i+1][med] = max(dp[i][med]+1, dp[i+1][med]);
			
		}
	}
	int ans = 0;
	for (int i = 1; i <= cnt; i++){
		ans = max(dp[n][i], ans);
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) solve();
	return 0;
}