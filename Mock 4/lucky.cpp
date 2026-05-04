#include <bits/stdc++.h>
using namespace std;

int n,A,B,tc;
vector<int> G[25];
int a[25];
int dp[1100000][21];
int tim[1100000][21];

void solve(){
	cin >> n;
	cin >> A >> B;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	if (n <= 20){
		for (int i = 0; i < n; i++) G[i].clear();
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		if (a[i]+a[j]==A || a[i]-a[j]==B){
			G[i].push_back(j);
		}
		for (int i = 0; i < n; i++){
			dp[1<<i][i] = n;
			tim[1<<i][i] = tc;
		}
		for (int i = 0; i < (1<<n); i++)
		for (int j = 0; j < n; j++)
		if (i&(1<<j) && tim[i][j]==tc){
			for (int k : G[j]){
				if (i&(1<<k)) continue;
				dp[i|(1<<k)][k] = j;
				tim[i|(1<<k)][k] = tc;
			}
		}
		int curr = n;
		int mask = (1<<n)-1;
		for (int i = 0; i < n; i++){
			if (tim[mask][i] == tc){
				curr = i;
				break;
			}
		}
		if (curr == n){
			cout << "NO\n";
		} else {
			cout << "YES\n";
			vector<int> ans(n+1);
			int cnt = n;
			while (curr != n){
				ans[cnt--] = curr;
				int pre = dp[mask][curr];
				mask ^= (1<<curr);
				curr = pre;
			}
			for (int i = 1; i <= n; i++){
				cout << a[ans[i]] << ' '; 
			}
			cout << "\n";
		}
		return;
	}
}

int main(){
	freopen("lucky.in", "r", stdin);
	freopen("lucky.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	for (tc = 1; tc <= T; tc++){
		solve();
	}
	return 0;
}


