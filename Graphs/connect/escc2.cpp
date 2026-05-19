// find the unavoidable paths (a,b)

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> G[100005];
bool bridge[200005];
int dfn[100005], low[100005];

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		G[a].push_back({b, i});
		G[b].push_back({a, i});
	}
	for (int i = 1; i <= n; i++){
		if (!dfn[i]) tarjan(i, 0);
	}
	return 0;
}