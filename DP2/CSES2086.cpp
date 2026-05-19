#include <bits/stdc++.h>
using namespace std;

int n, k;
long long dp[3005][3005];
int opt[3005][3005];
long long p[3005];

void MN(long long &x, long long y){
	if (x > y) x = y;
}

void DC(int l, int r, int opl, int opr, int i){
	// brute force pivot mid:
	int mid = (l+r)>>1;
	for (int x = opl; x <= opr; x++){
		long long cand = dp[i-1][x]+(p[mid]-p[x])*(p[mid]-p[x]);
		if (dp[i][mid] > cand){
			dp[i][mid] = cand;
			opt[i][mid] = x;
		}
	}
	if (l == r) return;	
	DC(l, mid, opl, opt[i][mid], i);
	DC(mid+1, r, opt[i][mid], opr, i);
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
		p[i] += p[i-1];
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	// naive solution: O(kn^2)
	// for (int i = 1; i <= k; i++){
	// 	for (int j = 1; j <= n; j++){
	// 		for (int r = 0; r < j; r++){
	// 			MN(dp[i][j], dp[i-1][r]+(p[j]-p[r])*(p[j]-p[r]));
	// 		}
	// 	}
	// }

	for (int i = 1; i <= k; i++){
		DC(1, n, 0, n-1, i);
	}
	cout << dp[k][n] << endl;

	return 0;
}






