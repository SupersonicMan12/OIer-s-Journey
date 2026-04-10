#include <bits/stdc++.h>
using namespace std;

int n, m;
// ans = sigma(S, T no intersection){f(S)g(T)(-2)^{n-|S|-|T|}}
// where f(S) is the number of ways to have at least set S nonleaves in T1
// and g(T) is the number of ways to have at least set T nonleaves in T2

// i, j, k:
// 1....i done, with T1 having 2...i parents assigned
// 				with T2 having 1.i-1 parents assigned
// 1....i has j in S
// i+1..n has k in T (pre-assigned, to be fulfilled)
// multiplication of 2^ is only as i sweeps from left to right

int dp[2][505][505];

int main(){
	cin >> n >> m;
	int x = 0;
	for (int i = 1; i < n; i++) dp[1][1][i] = 1;
	// pull into
	for (int i = 2; i <= n; i++){
		memset(dp[x], 0, sizeof(dp[x]));
		long long ans = 0;
		for (int j = 1; j < i; j++){
			for (int k = 1; k <= n-i-1; k++){
				// transfer from dp[i-1][j][k]
				if (dp[x^1][j][k]){

				}
			}
		}
		x ^= 1;
	}
	return 0;
}





