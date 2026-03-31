#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e16;
int n, m;
vector<pair<int,int>> G[200005];
long long d[200005];
bool vis[200005];

long long dij(int start, int end){
	priority_queue<pair<long long,int>> Q;
	memset(d, 0x3f, sizeof(d));
	d[start] = 0;
	Q.push({0LL, start});
	while (!Q.empty()){
		int x = Q.top().second; Q.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (auto [v, w]: G[x]){
			if (d[v] > d[x]+w){
				d[v] = d[x]+w;
				Q.push({-d[v], v});
			}
		}
	}
	if (d[end] > INF) return -1;
	else return d[end];
}

int main(){
	cin >> n >> m;
	int start, end, init;
	cin >> end >> start >> init;
	for (int i = 2; i <= m; i++){
		int a,b,c; cin >> a >> b >> c;
		G[a].push_back({b,c});
	}
	// run dijkstra starting from first element
	long long ans = dij(start, end);
	if (ans == -1) cout << -1 << '\n';
	else cout << ans + init <<'\n';
	return 0;
}