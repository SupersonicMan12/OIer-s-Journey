#include <bits/stdc++.h>
using namespace std;

// HILL CLIMBING

int n;
int a[55][55];
int xy[55];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) xy[i] = 1;
	
	int limit = 100*n*n;
	for (int i = 1; i <= limit; i++){
		bool mark = 1;
		for (int j = 1; j <= n; j++){
			// check if moveable
			int here = 0, there = 0;
			for (int k = 1; k <= n; k++){
				if (xy[k]==xy[j]) here += a[j][k];
				else there += a[j][k];
			}
			if (here < there) {
				xy[j] = 3-xy[j];
				mark = 0;
				break;
			}
		}
		if (mark) break;
	}
	for (int i = 1; i <= n; i++){
		if (xy[i] == 1) cout << 'X';
		else cout << 'Y';
	}
	cout << endl;
	return 0;
}