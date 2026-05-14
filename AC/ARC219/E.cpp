#include <bits/stdc++.h>
using namespace std;

int h, w;
pair<int,int> S[4000005];
void solve(){
	cin >> h >> w;
	int H = 2*h, W = 2*w;
	vector<vector<int>> grid(H+1, vector<int>(W+1));
	vector<string> ans(H+1, string(W+1,'A'));
	for (int i = 1; i <= H; i++){
		for (int j = 1; j <= W; j++){
			char c; cin >> c;
			grid[i][j] = (c=='x');
			ans[i][j] = 'A';
		}
	}
	int cnt = 0;
	for (int i = H; i >= 1; i--){
		S[++cnt] = {i,W};
	}
	for (int i = 1; i < H; i+=2){
		for (int j = W-1; j >= 1; j--){
			S[++cnt] = {i,j};
		}
		for (int j = 1; j < W; j++){
			S[++cnt] = {i+1,j};
		}
	}
	int l = 1, r = 2*h*w;
	int curr = 0;
	for (int i = l; i <= r; i++){
		curr += grid[S[i].first][S[i].second];
	}
	int target = h*w, cap = H*W;
	while (curr != target){
		curr -= grid[S[l].first][S[l].second];
		l++;
		r++; if (r > cap) r = 1;
		curr += grid[S[r].first][S[r].second];
	}
	for (int i = l; i <= r; i++){
		int x = S[i].first, y = S[i].second;
		ans[x][y] = 'B';
	}
	for (int i = 1; i <= H; i++){
		for (int j = 1; j <= W; j++){
			cout << ans[i][j];
		}
		cout << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}