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

int main(){
	string ss;
	int T = 0;
	while (cin >> ss){
		T++;
		memset(t, 0, sizeof(t));
		memset(sz, 0, sizeof(sz));
		int n = 0;
		int cnt = 0;
		while (ss != "9"){
			s[++n] = ss;
			int p = 0;
			for (char c : s[n]){
				if (!t[p][c-'0']) 
					t[p][c-'0'] = ++cnt;
				p = t[p][c-'0'];
			}
			sz[p] = 1;
			cin >> ss;
		}
		n--;
		dfs(0);
		bool fflag = 1;
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
				fflag = 0;
				cout << "Set " << T << " is not immediately decodable\n";
				break;
			}
		}
		if (fflag) cout << "Set " << T << " is immediately decodable\n";
	}
	return 0;
}

