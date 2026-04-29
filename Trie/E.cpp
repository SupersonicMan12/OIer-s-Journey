#include <bits/stdc++.h>
using namespace std;

int t[300][26];
bool mark[300];
int n, m, cnt;
// possible reach?
bool dp[1100005];

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		int x = 0;
		for (char c: s){
			if (!t[x][c-'a']) 
				t[x][c-'a'] = ++cnt;
			x = t[x][c-'a'];
		}
		mark[x] = 1;
	}
	while (m--){
		string s; cin >> s;
		int l = s.length();
		s = "#"+s;
		dp[0] = 1;
		// push dp
		for (int i = 0; i < l; i++){
			if (!dp[i]) continue;
			int x = 0;
			for (int j = i+1; j <= l; j++){
				if (!t[x][s[j]-'a']) break;
				else x = t[x][s[j]-'a'];
				if (mark[x]) dp[j] = 1;
			}	
		}
		for (int i = l; i >= 0; i--){
			if (dp[i]) {
				cout << i << '\n'; 
				break;
			}
		}
		for (int i = 0; i <= l; i++) dp[i]=0;
	}
	return 0;
}
