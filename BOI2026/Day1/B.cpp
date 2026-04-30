#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, q;
int Dx[4] = {1, 0, -1, 0};
int Dy[4] = {0, 1, 0, -1};
bool grid[1004][1004];
int d[1004][1004];
int start[1005], finish[1005];

int bfs(int sx, int sy, int ex, int ey){
	d[sx][sy] = 0;
	queue<pair<int, int>> Q;
	Q.push({sx,sy});
	while (!Q.empty()){
		pair<int,int> X = Q.front(); Q.pop();
		int x = X.first, y = X.second;
		if (x == ex && y == ey) break;
		for (int i = 0; i < 4; i++){
			int nx = x+Dx[i], ny = y+Dy[i];
			if (grid[nx][ny] && d[nx][ny]>d[x][y]+1){
				d[nx][ny] = d[x][y]+1;
				Q.push({nx, ny});
			}
		}
	}
	return d[ex][ey];
}

bool propertyFour(){
	for (int i = 1; i <= n; i++){
		int status = 0;
		for (int j = 1; j <= n; j++){
			status += abs(grid[i][j]-grid[i][j-1]);
		}
		if (status > 2) return 0;
	}
	return 1;
}

void prep(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (grid[i][j]){
				start[i] = j;
				break;
			}
		}
		for (int j = n; j >= 1; j--){
			if (grid[i][j]){
				finish[i] = j;
				break;
			}
		}
	}
}

int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			char c; cin >> c;
			grid[i][j] = (c=='#');
		}
	}
	if (n <= 200 && q <= 200){
		for (int i = 1; i <= q; i++){
			for (int x = 1; x <= n; x++){
				for (int y = 1; y <= n; y++){
					d[x][y] = INF;
				}
			}
			int i1,i2,j1,j2;
			cin >> i1 >> j1 >> i2 >> j2;
			cout << bfs(i1,j1,i2,j2) << '\n';
		}
	} else if (propertyFour()) {
		prep();
		for (int qq = 1; qq <= q; qq++){
			int i1,i2,j1,j2;
			cin >> i1 >> j1 >> i2 >> j2;
			if (i1 == i2){
				cout << abs(j1-j2) << '\n';
				continue;
			} else if (i1 > i2){
				swap(i1,i2); swap(j1,j2);
			}
			int x = j1, dist = 0;
			for (int i = i1; i < i2; i++){
				if (x < start[i]){
					dist += start[i]-x+1;
					x = start[i];
				} else if (x > finish[i]){
					dist += x-finish[i]+1;
					x = finish[i];
				} else {
					dist++;
				}
			}
			dist += abs(j2-x);
			cout << dist << '\n';
		}
	} else {
		cout << "give up\n";
	}
	return 0;
}


