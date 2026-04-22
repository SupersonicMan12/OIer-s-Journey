#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, p;
int x[5005];
int ps[5005];
int dp[5005][105];
int opt[5005][105];

int w(int l, int r){
	if ((r-l)%2){
		// even interval
		int mid = (r+l)>>1;
		return (ps[r]-ps[mid])-(ps[mid]-ps[l-1]);
	} else {
		// odd interval
		int mid = (r+l)>>1;
		return (ps[r]-ps[mid])-(ps[mid-1]-ps[l-1]);
	}
}

int main(){
	cin >> n >> p;
	for (int i = 1; i <= n; i++){
		cin >> x[i];
	}
	sort(x+1,x+n+1);
	for (int i = 1; i <= n; i++){
		ps[i] = ps[i-1]+x[i];
	}
	for (int i = 0; i <= n; i++)
		for (int j= 0; j <= p;j++) dp[i][j] = INF;
	for (int i = 1; i <= n; i++){
		dp[i][1] = w(1, i);
		opt[i][1] = 0;
	}
	dp[0][0] = 0;
	for (int j = 2; j <= p; j++){
		opt[n + 1][j] = n-1;
		for (int i = n; i >= j; i--){
			int best = INF, theone = 0;
			for (int k = opt[i][j-1]; k <= opt[i+1][j]; k++){
				if (k >= i) break;
				int calc = dp[k][j-1] + w(k+1, i);
				if (calc <= best){
					best = calc;
					theone = k;
				}
			}
			dp[i][j] = best;
			opt[i][j] = theone;
		}
	}
	cout << dp[n][p] << '\n';

	return 0;
}



