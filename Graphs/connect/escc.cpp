#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, ans;
int edge[100005][2];
vector<pair<int,int>> G[100005];
int dfn[100005], low[100005];
bool bridge[100005];
int d[100005];

void dfs(int x, int e){
	low[x] = dfn[x] = ++cnt;
	for (auto [v,ee] : G[x]){
		if (ee == e) continue;
		if (dfn[v]){
			low[x] = min(low[x], dfn[v]);
		} else {
			dfs(v, ee);
			low[x] = min(low[x], low[v]);
			if (low[v] > dfn[x]) bridge[ee] = 1;
		}
	}
}

int color[100005],cc;
vector<int> GG[100005];
void dfs2(int x){
	color[x] = cc;
	for (auto [v, e]: G[x]){
		if (color[v] || bridge[e]) continue;
		dfs2(v);
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b;
		edge[i][0] = a;
		edge[i][1] = b;
		G[a].push_back({b,i});
		G[b].push_back({a,i});
	}
	cnt = ans = 0;
	dfs(1,0);
	for (int i = 1; i <= n; i++){
		if (!color[i]) {cc++;dfs2(i);}
	}
	for (int i = 1; i <= m; i++){
		if (bridge[i]){
			d[color[edge[i][0]]]++;
			d[color[edge[i][1]]]++;
		}
	}
	if (cc == 1){
		cout << 1 << '\n';
		return 0;
	}
	int grand = 0;
	for (int i = 1; i <= cc; i++){
		if (d[i]==1) grand++;
	}
	cout << (grand+1)/2 << '\n';
	
	return 0;
}



