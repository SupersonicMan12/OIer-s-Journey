#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, bool> M;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		string S;
		for (char c: s){
			S += '0'+'1'-c;
		}
		M[S] = 1;
	}
	for (int i = 1; i <= n+1; i++){
		string s(m, '0');
		int cnt = 0;
		while ((1<<cnt) <= i){
			s[cnt] = '0'+((i>>cnt)&1);
			cnt++;
		}
		for (int j = cnt; j < m; j++){
			s[j] = '0';
		}
		if (!M[s]){
			cout << "Yes\n";
			cout << s << '\n';
			return 0;
		}
	}
	
	cout << "No\n";
	return 0;
}