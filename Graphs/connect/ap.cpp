#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<pair<int,int>> G[100005];
int dfn[100005], low[100005];
bool ans[100005];

void dfs(int x, int e, int st){
	low[x] = dfn[x] = ++cnt;
	int c = 0;
	for (auto [v,ee] : G[x]){
		if (ee == e) continue;
		if (dfn[v]){
			low[x] = min(low[x], dfn[v]);
		} else {
			dfs(v, ee, st); c++;
			low[x] = min(low[x], low[v]);
			if (x != st && low[v] >= dfn[x]) {
				ans[x] = 1;
			}
		}
	}
	if (x == st && c > 1) ans[x] = 1;
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		G[a].push_back({b,i});
		G[b].push_back({a,i});
	}
	cnt = 0;
	int k = 0;
	for (int i = 1; i <= n; i++){
		if (!dfn[i]) dfs(i,0,i);
		if (ans[i]) k++;
	}
	cout << k << '\n';
	for (int i = 1; i <= n; i++){
		if (ans[i]){
			cout << i << ' ';
		}
	}
	
	return 0;
}