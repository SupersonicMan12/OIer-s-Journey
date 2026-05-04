#include <bits/stdc++.h>
using namespace std;

int n, t;
bool taken[505];
vector<int> seq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	for (int i = 1; i <= n; i++){
		for (int j = 1, nj; j <= n; j++){
			if (i == j) {cout << 0; continue;}
			if (j<i) nj = j+n;
			else nj = j;
			if (nj-i<=(n-1)/2) cout << 1;
			else cout << 0;
		}
		cout << '\n';
	}
	while (t--){
		memset(taken,0,sizeof(taken));

	}
	return 0;
}