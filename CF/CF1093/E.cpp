#include <bits/stdc++.h>
using namespace std;

int friends[200005];
int red[200005];
bool isred[200005];
vector<int> G[200005];

void solve(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		G[i].clear();
		red[i] = 0;
		friends[i] = 0;
		char c; cin >> c;
		isred[i] = (c=='1');
	}
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		friends[a]++;
		friends[b]++;
	}
	if (n==1){
		cout << 0 << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++){
		if (isred[i]){
			for (int v : G[i]){
				red[v]++;
			}
		}
	}
	priority_queue<pair<long double, int>> P;
	for (int i = 1; i <= n; i++){
		if (!isred[i]){
			P.push({1.0*red[i]/friends[i], i});
		}
	}

	double total = 0;
	while (!P.empty()){
		int x = P.top().second; 
		double vv = P.top().first;
		P.pop();
		if (isred[x]) continue;
		total += 1.0/vv;
		isred[x] = 1;
		for (int v : G[x]){
			if (isred[v]) continue;
			red[v]++;
			P.push({1.0*red[v]/friends[v], v});
		}
	}
	cout << fixed << setprecision(15) << total << '\n';
}

int main(){
	int t; cin >> t;
	while (t--) solve();

	return 0;
}