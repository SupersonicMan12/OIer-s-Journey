// finds a maze / tree-like structure

#include <bits/stdc++.h>
using namespace std;

int n, m, k, achieve;
int grid[1026][1026];
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

bool inbound(int x, int y){
	return (x <= n && x >= 1 && y <= m && y >= 1);
}

int cnt_neigh(int x, int y){
	int ans = 0;
	for (int d = 0; d < 4; d++){
		int nx = x + DX[d];
		int ny = y + DY[d];
		if (inbound(nx, ny))
		if (grid[nx][ny]==2) ans++;
	}
	return ans;
}

void dfs(int x, int y){
	for (int dir = 0; dir < 4; dir++){
		int nx = x+DX[dir], ny = y+DY[dir];
		vector<pair<int,int>> path;
		while (inbound(nx, ny) && !grid[nx][ny] && cnt_neigh(nx, ny) == 1){
			grid[nx][ny] = 2;
			path.push_back({nx,ny});
			nx += DX[dir]; 
			ny += DY[dir];
		}
		nx -= DX[dir]; ny -= DY[dir];
		if (nx == x && ny == y) continue;
		path.pop_back();
		if (!path.empty()) path.pop_back();
		for (auto [nx, ny]: path){
			int nnx = nx + DX[(dir+1)%4], nny = ny + DY[(dir+1)%4];
			if (inbound(nnx, nny) && !grid[nnx][nny] && cnt_neigh(nnx, nny) == 1){
				grid[nnx][nny] = 2;
				achieve++;
			}
			nnx = nx + DX[(dir+3)%4], nny = ny + DY[(dir+3)%4];
			if (inbound(nnx, nny) && !grid[nnx][nny] && cnt_neigh(nnx, nny) == 1){
				grid[nnx][nny] = 2;
				achieve++;
			}
		}
		dfs(nx, ny);
	}
}

int main(){
	freopen("11", "r", stdin);
	freopen("11.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			char c ; cin >> c;
			if (c == '#') grid[i][j] = 1;
			else grid[i][j] = 0;
		}
	}
	int Xstart, Ystart;
	for (int i = n/3; i < 2*n/3; i++){
		for (int j = m/3; j < 2*m/3; j++){
			if (!grid[i][j]){
				Xstart = i;
				Ystart = j;
			}
		}
	}
	cout << grid[Xstart][Ystart] << endl;
	grid[Xstart][Ystart] = 2;
	dfs(Xstart, Ystart);
	cout << achieve << '/' << k << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (grid[i][j] == 0) cout << 'X';
			if (grid[i][j] == 1) cout << '#';
			if (grid[i][j] == 2) cout << '.';
		}
		cout << '\n';
	}

	return 0;
}



