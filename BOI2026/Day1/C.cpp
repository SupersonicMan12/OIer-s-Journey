#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n, m, k;
vector<int> G[200005];
bool vis[200005];
int path[200005], pt;
vector<int> ring;
bool winner[200005];

int edge[200100][2];
int fa[200005], dep[200005];
int find(int x){
	if (fa[x]==x) return x;
	else return fa[x] = find(fa[x]);
}
vector<int> T[200005];
int up[200005][19];
int newnodes[26],N;
map<int,int> revv;
vector<pair<int,int>> GG[26];
int ccnt[26];
int dp[10005][25][25][2];

int find(int start, int end){
	if (start == end) return 0;
	vis[start] = 1;
	for (int v : G[start]){
		if (vis[v]) continue;
		int ret = find(v, end);
		if (ret != -1) return ret+1;
	}
	return -1;
}

bool find_ring(int x, int prev){
	path[++pt] = x;
	vis[x] = 1;
	for (int v : G[x]){
		if (v == prev) continue;
		if (vis[v]){
			// ring found
			while (path[pt] != v){
				ring.push_back(path[pt--]);
			}
			ring.push_back(v);
			return 1;
		}
		if (find_ring(v, x)) return 1;
	}
	pt--;
	return 0;
}

pair<int,int> dfs(int x, int fa){
	if (winner[x]) return make_pair(0, x);
	for (int v : G[x]){
		if (v == fa) continue;
		pair<int,int> ret = dfs(v, x);
		if (ret.first != -1){
			return make_pair(ret.first+1, ret.second);
		}
	}
	return make_pair(-1, 0);
}

void build_tree(int x, int f){
	up[x][0] = f;
	for (int i = 1; i <= 18; i++){
		up[x][i] = up[up[x][i-1]][i-1];
	}
	for (int v : T[x]){
		if (v == f) continue;
		dep[v] = dep[x]+1;
		build_tree(v, x);
	}
}

int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 18; i >= 0; i--){
		if (dep[x]-(1<<i)>=dep[y]){
			x = up[x][i];
		}
	}
	if (x == y) return x;
	for (int i = 18; i >= 0; i--){
		if (up[x][i] != up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}

int dist(int x, int y){
	int z = lca(x, y);
	return dep[x] + dep[y] - 2 * dep[z];
}

bool on_path(int x, int a, int b){
	return dist(a, x) + dist(x, b) == dist(a, b);
}

bool ok(int a, int c, int t1, int t2){
	if (a == c && t1 == t2) return 0;
	else return 1;
}

int main(){
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		int a,b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		edge[i][0] = a;
		edge[i][1] = b;
	}
	if (m == n-1){
		if (find(1, n) == k){
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	} else if (m == n){
		// ring tree
		find_ring(1, 0);
		for (int x : ring) winner[x] = 1;
		pair<int,int> f1 = dfs(1, 0);
		pair<int,int> fn = dfs(n, 0);
		int l = ring.size();
		int i1, i2;
		for (int x = 0; x < l; x++){
			if (f1.second == ring[x]) i1 = x;
			if (fn.second == ring[x]) i2 = x;
		}
		k -= f1.first;
		k -= fn.first;
		int ans = 0;
		if ((i1-i2+l)%l == k%l) ans++;
		if ((i2-i1+l)%l == k%l) ans++;
		cout << ans << '\n';
	} else {
		for (int i = 1; i <= n; i++) fa[i] = i;
		vector<int> bridge;
		for (int i = 1; i <= m; i++){
			int x = edge[i][0], y = edge[i][1];
			int fx = find(x), fy = find(y);
			if (fx == fy){
				bridge.push_back(i);
			} else {
				fa[fx] = fy;
				T[x].push_back(y);
				T[y].push_back(x);
			}
		}
		build_tree(1, 0);
		for (int b : bridge){
			if (!revv.count(edge[b][0])){
				newnodes[++N] = edge[b][0];
				revv[edge[b][0]] = N;
			} 
			if (!revv.count(edge[b][1])){
				newnodes[++N] = edge[b][1];
				revv[edge[b][1]] = N;
			} 
			GG[revv[edge[b][1]]].push_back({revv[edge[b][0]], 1});
			ccnt[revv[edge[b][1]]]++;
			GG[revv[edge[b][0]]].push_back({revv[edge[b][1]], 1});
			ccnt[revv[edge[b][0]]]++;
		}
		if (!revv.count(1)){
			newnodes[++N] = 1;
			revv[1] = N;
		} 
		if (!revv.count(n)){
			newnodes[++N] = n;
			revv[n] = N;
		} 
		for (int i = 1; i <= N; i++){
			for (int j = i+1; j <= N; j++){
				int a = newnodes[i];
				int b = newnodes[j];
				bool bad = 0;
				for (int z = 1; z <= N; z++){
					if (z == i || z == j) continue;
					if (on_path(newnodes[z], a, b)){
						bad = 1;
						break;
					}
				}
				if (bad) continue;
				int l = dist(a, b);
				GG[i].push_back({j, l});
				GG[j].push_back({i, l});
			}
		}
		dp[0][0][revv[1]][0] = 1;
		for (int i = 0; i < k; i++){
			for (int a = 0; a <= N; a++){
				for (int b = 1; b <= N; b++){
					int len = GG[b].size();
					// i = 0 means bridge, 1 means complete
					for (int idx = 0; idx < len; idx++){
						int c = GG[b][idx].first;
						int w = GG[b][idx].second;
						if (i + w > k) continue;
						int idxx = (idx<ccnt[b])?0:1;
						for (int t = 0; t <= 1; t++){
							if (ok(a,c,t,idxx)){
								(dp[i+w][b][c][idxx] += dp[i][a][b][t]) %= MOD;
								// if (i + w == k){
								// 	cout << dp[i+w][b][c][idxx] << '\n';
								// }
								// cout << i+w << ' ' << b << ' ' << c << ' ' << i << '\n';
							} 
						}
					}
				}
			}
		}
		int ans = 0;
		for (int prev = 1; prev <= N; prev++){
			(ans += dp[k][prev][revv[n]][0]+dp[k][prev][revv[n]][1]) %= MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}







