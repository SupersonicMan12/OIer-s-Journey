#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> G[300005];
bool vis[300005];

void dfs(int x){
	vis[x] = 1;
	for (int v : G[x]){
		if (vis[v]) continue;
		dfs(v);
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
	}
	dfs(1);
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (vis[i]) cnt++;
	}
	cout << cnt << '\n';

	return 0;
}