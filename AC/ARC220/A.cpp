#include <bits/stdc++.h>
using namespace std;

int dp[100005];

void solve(){
	int n; cin >> n;
	if (!dp[n]){
		cout << "No\n";
		return;
	}
	vector<int> V;
	int x = n;
	while (x != 1){
		V.push_back(dp[x]);
		x = x-(dp[x]*dp[x]-1);
	}
	priority_queue<int, vector<int>, greater<int>> P;
	P.push(1);
	for (int v : V){
		int x = P.top(); P.pop();
		int times = v*v;
		int ele = x*v;
		for (int i = 1; i <= times; i++){
			P.push(ele);
		}
	}
	cout << "Yes\n";
	while (!P.empty()){
		int x = P.top(); P.pop();
		cout << x << ' ';
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[1] = 1;
	for (int i = 1; i <= 316; i++){
		int adds = i*i-1;
		for (int j = adds+1; j <= 100000; j++){
			if (dp[j-adds]) dp[j] = i;
		}
	}
	for (int i = 1; i <= 100; i++) cout << dp[i] << ' ';
	int T; cin >> T;
	while (T--) solve();

	return 0;
}