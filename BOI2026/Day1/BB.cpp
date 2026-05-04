#include <bits/stdc++.h>
using namespace std;

int n, q;
bool grid[1005][1005];
int hor[1005][1005];
int ver[1005][1005];

vector<int> G[2][1000005];
int fa[2][1000005][21];
int dep[2][1000005];
bool vis[2][1000005];

void dfs(int x, int f, int ind){
	vis[ind][x] = 1;
	fa[ind][x][0] = f;
	for (int i = 1; i <= 20; i++){
		fa[ind][x][i] = fa[ind][fa[ind][x][i-1]][i-1];
	}
	dep[ind][x] = dep[ind][f]+1;
	for (int v : G[ind][x]){
		if (f==v) continue;
		if (vis[ind][v]) continue;
		dfs(v, x, ind);
	}
}

int lca(int x, int y, int ind){
	if (dep[ind][x] < dep[ind][y]) swap(x, y);
	for (int i = 20; i >= 0; i--){
		if (dep[ind][x]-(1<<i) >= dep[ind][y]){
			x = fa[ind][x][i];
		}
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--){
		if (fa[ind][x][i]!=fa[ind][y][i]){
			x = fa[ind][x][i];
			y = fa[ind][y][i];
		}
	}
	return fa[ind][x][0];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			char c; cin >> c;
			grid[i][j] = (c=='#');
		}
	}
	int color = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (grid[i][j]) hor[i][j] = color;
			else if (grid[i][j-1]) color++;
		}
		if (grid[i][n]) color++;
	}
	color = 1;
	for (int j = 1; j <= n; j++){
		for (int i = 1; i <= n; i++){
			if (grid[i][j]) ver[i][j] = color;
			else if (grid[i-1][j]) color++;
		}
		if (grid[n][j]) color++;
	}
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n; j++){
			if (grid[i][j] && grid[i+1][j]){
				G[0][hor[i][j]].push_back(hor[i+1][j]);
			}
			if (grid[i][j] && grid[i-1][j]){
				G[0][hor[i][j]].push_back(hor[i-1][j]);
			}
		}
	}
	for (int j = 1; j <= n; j++){
		for (int i = 1; i <= n; i++){
			if (grid[i][j] && grid[i][j+1]){
				G[1][ver[i][j]].push_back(ver[i][j+1]);
			}
			if (grid[i][j] && grid[i][j-1]){
				G[1][ver[i][j]].push_back(ver[i][j-1]);
			}
		}
	}
	dfs(1,0,0);
	dfs(1,0,1);
	for (int i = 1; i <= q; i++){
		int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
		int hx = hor[i1][j1];
		int vx = ver[i1][j1];
		int hy = hor[i2][j2];
		int vy = ver[i2][j2];
		int horizontal = dep[0][hx]+dep[0][hy]-2*dep[0][lca(hx, hy, 0)];
		int vertical = dep[1][vx]+dep[1][vy]-2*dep[1][lca(vx, vy, 1)];
		cout << horizontal+vertical << '\n';
	}

	return 0;
}

