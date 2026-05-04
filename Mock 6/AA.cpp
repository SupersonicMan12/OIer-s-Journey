#include <bits/stdc++.h>
using namespace std;

long long l, r, p;

const int primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
const int MAXX = 2944733;
int num[MAXX], cnt, dp[MAXX];

void dfs(int i, long long x){
	if (i == 25) {
		num[++cnt] = x;
		return;
	}
	while (x <= r){
		dfs(i+1, x);
		x = x*primes[i];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> r >> p;
	dfs(0, 1);
	sort(num+1, num+cnt+1);

	memset(dp, 0x3f, sizeof(dp));
	dp[1] = 0;
	for (int i = 2; i <= p; i++){
		int l = 1; // represents i*number[j]
		for (int j = 1; j <= cnt; j++){
			while (l <= cnt && i*num[j]>num[l]) l++;
			if (l <= cnt){
				dp[l] = min(dp[j]+1, dp[l]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= cnt; i++){
		if (num[i] <= r && num[i] >= l && dp[i]<=p){
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}


