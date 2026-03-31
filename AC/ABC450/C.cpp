#include <bits/stdc++.h>
using namespace std;

int h, w;
bool white[1005][1005];
bool vis[1005][1005];
int cnt;

bool dfs(int x, int y){
	// mark means hitting the border
	vis[x][y] = 1;
	bool mark = (x == 1 || x == h || y == 1 || y == w);
	if (x > 1 && !vis[x-1][y] && white[x-1][y] && dfs(x-1, y)) mark = 1;
	if (x < h && !vis[x+1][y] && white[x+1][y] && dfs(x+1, y)) mark = 1;
	if (y > 1 && !vis[x][y-1] && white[x][y-1] && dfs(x, y-1)) mark = 1;
	if (y < w && !vis[x][y+1] && white[x][y+1] && dfs(x, y+1)) mark = 1;
	return mark;
}

int main(){
	cin >> h >> w;
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			char c; cin >> c;
			white[i][j] = (c == '.');
		}
	}
	cnt = 0;
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			if (white[i][j] && !vis[i][j]){
				if (!dfs(i,j)) cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}