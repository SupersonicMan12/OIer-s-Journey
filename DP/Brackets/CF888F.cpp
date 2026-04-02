#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n;
bool can[505][505];
int f[505][505]; // overall ways to do [l, r]
int g[505][505]; // ways to do [l, r] with (l, r) connected

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> can[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		f[i][i] = g[i][i] = 1;
	}
	for (int d = 2; d <= n; d++){
		for (int l = 1; l+d-1 <= n; l++){
			int r = l+d-1;
			// consider interval [l, r];
			// g(l, r): 
			if (can[l][r]){
				for (int mid = l; mid < r; mid++){
					(g[l][r] += 1LL*f[l][mid]*f[mid+1][r]%MOD)%=MOD;
				}
			}
			// notice start: mid = l is a mistake, but f[l][r] is 0 anyway...
			for (int mid = l+1; mid <= r; mid++){
				(f[l][r] += 1LL*g[l][mid]*f[mid][r]%MOD)%=MOD;
			}
		}
	}
	cout << f[1][n] << '\n';
	return 0;
}

// Motivation: starting from f: there exists someone connected to leftmost element, extremal, then find the need for g.