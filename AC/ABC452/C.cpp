#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[11], b[11];
string s[200005];
int grid[11][11][28];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++){
		cin >> s[i];
		s[i] = "#"+s[i];
		int l = s[i].length()-1;
		for (int j = 1; j <= l; j++){
			grid[l][j][s[i][j]-'a']++;
		}
	}
	for (int i = 1; i <= m; i++){
		if (s[i].length() != n+1) {cout << "No\n"; continue;}
		bool flag = 1;
		for (int j = 1; j <= n; j++){
			if (!grid[a[j]][b[j]][s[i][j]-'a']){
				cout << "No\n";
				flag = 0;
				break;
			}
		}
		if (flag) cout << "Yes\n";
	}


	return 0; 
}