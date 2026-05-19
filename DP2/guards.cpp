#include <bits/stdc++.h>
using namespace std;

long long p[8005];
long long dp[3005][8005];
int opt[8005];
int n, k;

long long cost(int l, int r){
	return (p[r]-p[l-1])*(r-l+1);
}

void DC(int l, int r, int opl, int opr, int i){
	if (l > r) return;
	int mid = (l+r)>>1;
	for (int x = opl; x <= opr; x++){
		long long cand = dp[i-1][x]+cost(x+1, mid);
		if (dp[i][mid] > cand){
			dp[i][mid] = cand;
			opt[mid] = x;
		}
	}
	if (l == r) return;
	DC(l, mid-1, opl, opt[mid], i);
	DC(mid+1, r, opt[mid], opr, i);
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
		p[i] += p[i-1];
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= k; i++){
		DC(1, n, 0, n-1, i);
	}
	cout << dp[k][n] << endl;
	return 0;
}