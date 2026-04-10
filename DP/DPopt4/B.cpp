// LOJ 6069 Tower

#include <bits/stdc++.h>
using namespace std;

int n, l, m; 
// 1..i placed, j intervals, sum max = k
int dp[2][105][10005];
int inv[105];

void mv(int& x, int y){
	(x += y) %= m;
}

int pow(int x, int n){
	int r = 1;
	while (n){
		if (n & 1) r = 1LL*r*x%m;
		x = 1LL*x*x%m;
		n >>= 1;
	}
	return r;
}

int C(int x, int y){
	if(x < y || y < 0) return 0;
	vector<int> nums(y);
	for(int i = 0; i < y; i++) nums[i] = x - i;
	for(int k = 2; k <= y; k++){
		int rem = k;
		for(int i = 0; i < y && rem > 1; i++){
			int g = __gcd(rem, nums[i]);
			nums[i] /= g;
			rem /= g;
		}
	}
	long long ans = 1;
	for(int i = 0; i < y; i++)
		ans = ans * nums[i] % m;
	return ans;
}

int main(){
	cin >> n >> l >> m;
	for (int i = 1; i <= n; i++){
		inv[i] = pow(i, m-2);
	}
	dp[0][0][0] = 1;
	int N = n*n;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= i; j++){
			for (int k = 0; k <= N; k++){
				// merge into existing
				if (k >= i)
				mv(dp[1][j][k], 1LL*dp[0][j][k-i]*(2*j)%m);
				// new self
				if (j >= 1)
				mv(dp[1][j][k], 1LL*dp[0][j-1][k]*(j)%m); 
				// combine two
				if (k >= 2*i)
				mv(dp[1][j][k], 1LL*dp[0][j+1][k-2*i]*(j)%m);
			}
		}
		memcpy(dp[0], dp[1], sizeof(dp[1]));
		memset(dp[1], 0, sizeof(dp[1]));
	}
	long long ans = 0;
	for (int k = 0; k <= N; k++){
		int bans = dp[0][1][k];
		if (!bans) continue;
		(ans += 1LL* bans * C(l-k+n-1, n) % m) %= m;
	}
	cout << ans << '\n';
	return 0;
}



