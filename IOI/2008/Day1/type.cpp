#include <bits/stdc++.h>
using namespace std;

int n, cnt;
bool mark[500005];
int nxt[500005][26];
int dep[500005];
string ANS;

void dfs(int x){
	if (mark[x]) ANS.push_back('P');
	priority_queue<pair<int,int>> P;
	for (int i = 0; i < 26; i++){
		if (!nxt[x][i]) continue;
		P.push({-dep[nxt[x][i]], i});
	}
	while (!P.empty()){
		int i = P.top().second; P.pop();
		ANS.push_back('a'+i);
		dfs(nxt[x][i]);
		ANS.push_back('-');
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cnt = 0;
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		int l = s.length();
		int p = 0;
		for (char c : s){
			if (!nxt[p][c-'a']){
				nxt[p][c-'a'] = ++cnt;
			}
			p = nxt[p][c-'a'];
			dep[p] = max(dep[p], l);
		}
		mark[p] = 1;
	}
	dfs(0);
	while (ANS.back()=='-') ANS.pop_back();
	cout << (int)ANS.size() << '\n';
	for (char c : ANS) cout << c << '\n';

	return 0;
}