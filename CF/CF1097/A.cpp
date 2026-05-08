#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;

void solve(){
	cin >> n;
	cin >> s; s = "#"+s;
	cin >> t; t = "#"+t;
	int a = 0, b = 0; // keep these balanced
	for (int i = 1; i <= n; i++){
		int mode = (s[i]=='(')+(t[i]=='(');
		if (mode == 2){
			a++; b++;
		} else if (mode == 1){
			if (a==0&&b==0){
				cout << "NO\n";
				return;
			} 
			if (a < b){
				a++; b--;
			} else {
				b++; a--;
			}
		} else {
			if (a==0||b==0){
				cout << "NO\n";
				return;
			} else {
				a--; b--;
			}
		}
	}
	if (a != 0 || b != 0) cout << "NO\n";
	else cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while (T--){
		solve();
	}
	return 0;
}