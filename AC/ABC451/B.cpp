#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105];

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int x, y; cin >> x >> y;
		a[y]++; a[x]--;
	}
	for (int i = 1; i <= m; i++){
		cout << a[i] << '\n';
	}

	return 0;
}