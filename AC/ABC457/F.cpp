#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n;
int d[200005];
int dp[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++){
		cin >> d[i];
	}
	if (d[n-1] != 1){
		cout << 0 << '\n';
		return;
	}
	dp[n] = dp[n-1] = 1;
	int M = 1;
	for (int i = n-2; i >= 1; i--){
		
	}
	return 0;
}