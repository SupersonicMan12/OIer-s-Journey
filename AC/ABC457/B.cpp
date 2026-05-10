#include <bits/stdc++.h>
using namespace std;

vector<int> G[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		int l; cin >> l;
		for (int j = 1; j <=l; j++){
			int x; cin >> x;
			G[i].push_back(x);
		}
	}
	int x, y; cin >> x >> y;
	cout << G[x][y-1] << endl;
	return 0;
}