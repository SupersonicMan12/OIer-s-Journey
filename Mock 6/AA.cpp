#include <bits/stdc++.h>
using namespace std;

long long l, r, p;

const int INF = 1e9;
const int primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
const int MAXX = 2944733;
long long num[MAXX], cnt, dp[MAXX];
bool works[MAXX];

void dfs(int i, long long x){
	if (i == 25 || primes[i] > p) {
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

	for (int i = 1; i <= cnt; i++) dp[i] = INF;
	dp[1] = 0;
	for (int i = 2; i <= p; i++){
		int ll = 1; // represents i*number[j]
		for (int j = 1; j <= cnt; j++){
			while (ll <= cnt && num[j]*i>num[ll]) ll++;
			if (ll <= cnt){
				dp[ll] = min(dp[j]+1, dp[ll]);
				if (dp[ll]+i <= p) works[ll] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= cnt; i++){
		if (num[i] <= r && num[i] >= l && works[i]){
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}


