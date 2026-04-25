#include <bits/stdc++.h>
using namespace std;

int h,w; 
bool grid[11][11];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w;
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			char c; cin >> c;
			grid[i][j] = (c=='#');
		}
	}
	int cnt = 0;
	for (int h1 = 1; h1 <= h; h1++)
	for (int h2 = h1; h2 <= h; h2++)
	for (int w1 = 1; w1 <= w; w1++)
	for (int w2 = w1; w2 <= w; w2++){
		bool yes = 1;
		for (int i = h1; i <= h2; i++)
		for (int j = w1; j <= w2; j++){
			if (grid[h1+h2-i][w1+w2-j]!=grid[i][j]){
				yes = 0;
			}
		}
		if (yes) cnt++;
	}
	cout << cnt << endl;

	return 0;
}