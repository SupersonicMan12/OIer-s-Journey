#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int grid[1025][1025];

int main(){
	freopen("05", "r", stdin);
	freopen("05.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n/3; i++){
		string s1;
		for (int j = 1; j <= m; j++) s1.push_back('.');
		string s2; s2.push_back('.'); s2.push_back('X');
		for (int j = 1; j < m/2; j++){
			s2.push_back('.');
			s2.push_back('X');
		}
		string s3; s3.push_back('.'); s3.push_back('X');
		for (int j = 1; j < m/2; j++){
			s3.push_back('X');
			s3.push_back('.');
		}
		cout << s1 << '\n' << s2 << '\n' << s3 << '\n';
	}
	string s;
	for (int j = 1; j <= m; j++) s.push_back('.');
	cout << s << '\n';
	// if (n == 128){
	// 	string s1;
	// 	for (int j = 1; j <= m; j++) s1.push_back('X');
	// 	cout << s1 << '\n';
	// }
}