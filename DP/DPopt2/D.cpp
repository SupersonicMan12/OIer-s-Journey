/*

5 5 2
6 0
8 3
4 5
6 7
9 10

N nodes, from 1: largest jump D, max jump M, maximize sum v, given:
v d

N, M <= 1e4, D <= 20000, d <= 1e9, ai <= 1000

obvious linear is one of the best answers

dp[y][x] = best ending at x having jumped y times.

dp[y][x] = MAX dp[y-1][k] for (k < x and d[x]-d[k] <= D), pq is linear

with increasing y but decreasing dp value
<y, dp>

O(n^2) achievable

*/

#include <bits/stdc++.h>
using namespace std;
int n,D,m, head, tail;
int v[10005],d[10005];
int q[10005]; 
int dp[2][10005];

int main(){
	cin >> n >> D >> m;
	for (int i = 1; i <= n; i++){
		cin >> v[i] >> d[i];
	}
	memset(dp, 0x8f, sizeof(dp));
	int ans = v[1];
	dp[0][1] = v[1];
	for (int i = 1; i <= m; i++){
		head = tail = 1;
		q[1] = 0;
		for (int x = 1; x <= n; x++){
			while (head >= tail && d[x]-d[q[tail]]>D) tail++;
			// nonempty, ghost value!!
			if (head >= tail) dp[1][x] = dp[0][q[tail]]+v[x];
			while (head>=tail && dp[0][x]>=dp[0][q[head]]) head--;
			q[++head] = x;
		}
		memcpy(dp[0], dp[1], sizeof(dp[1]));
		memset(dp[1], 0x8f, sizeof(dp[1]));
		for (int x = 1; x <= n; x++) ans = max(ans, dp[0][x]);
	}
	cout << ans << '\n';

	return 0;
}




