#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, ans;
vector<pair<int,int>> G[100005];
int dfn[100005], low[100005];

void dfs(int x, int e){
	low[x] = dfn[x] = ++cnt;
	for (auto [v,ee] : G[x]){
		if (ee == e) continue;
		if (dfn[v]){
			low[x] = min(low[x], dfn[v]);
		} else {
			dfs(v, ee);
			low[x] = min(low[x], low[v]);
		}
		if (low[v] > dfn[x]) ans++;
	}
}

int main(){
	cin >> n >> m;
	while (n){
		for (int i = 1; i <= m; i++){
			int a, b; cin >> a >> b;
			G[a].push_back({b,i});
			G[b].push_back({a,i});
		}
		cnt = ans = 0;
		for (int i = 1; i <= n; i++){
			if (!dfn[i]) dfs(i,0);
		}
		for (int i = 1; i <= n; i++){
			dfn[i]=low[i]=0;
			G[i].clear();
		}
		cout << ans << '\n';
		cin >> n >> m;
	}
	
	return 0;
}