#include <bits/stdc++.h>
using namespace std;

string s[10005];
int t[100005][10];
int sz[100005];

void dfs(int x){
	for (int i = 0; i < 10; i++){
		if (t[x][i]) {
			dfs(t[x][i]);
			sz[x] += sz[t[x][i]];
		}
	}
}

void solve(){
	memset(t, 0, sizeof(t));
	memset(sz, 0, sizeof(sz));
	int n; cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		int p = 0;
		for (char c : s[i]){
			if (!t[p][c-'0']) 
				t[p][c-'0'] = ++cnt;
			p = t[p][c-'0'];
		}
		sz[p] = 1;
	}
	dfs(0);
	for (int i = 1; i <= n; i++){
		bool flag = 1;
		int p = 0;
		for (char c : s[i]){
			if (!t[p][c-'0']) {
				flag = 0;
				break;
			}
			p = t[p][c-'0'];
		}
		if (flag && sz[p] > 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}

int main(){
	int T; cin >> T;
	while (T--) solve();
	return 0;
}