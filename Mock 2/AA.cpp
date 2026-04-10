#include <bits/stdc++.h>
using namespace std;

int n, H;
long long ans = 0;
int h[1000006];
int w[1000006];
// [i, i+2^j)
int mn[1000006][21];
long long l[1000006];
long long r[1000006];

int main(){
	cin >> n >> H;
	for (int i = 1; i <= n; i++){
		cin >> h[i] >> w[i];
		mn[i][0] = h[i];
		w[i] += w[i-1];
	}
	for (int j = 1; j <= 20; j++){
		for (int i = 1; i+(1<<j) <= n; i++){
			mn[i][j] = min(mn[i][j], mn[i+(1<<j)][j]);
		}
	}
	for (int x = 1; x <= n; x++){
		int hh = max(H, h[x]);
		int i = x+1;
		for (int j = 20; j >= 0; j--){
			if ((i + (1<<j) <= n) && (mn[i][j] >= hh)) 
				i += (1<<j); 
		}
		// [x, i) 
		cout << x << ' ' << i << '\n';
		l[x] = (w[i-1]-w[x-1])*hh;
	}

	for (int j = 1; j <= 20; j++){
		for (int i = n; i-(1<<j) >= 1; i--){
			mn[i][j] = min(mn[i][j], mn[i-(1<<j)][j]);
		}
	}
	for (int x = 1; x <= n; x++){
		int hh = max(H, h[x]);
		int i = x-1;
		for (int j = 20; j >= 0; j--){
			if ((i - (1<<j) >= 1) && (mn[i][j] >= hh)) 
				i -= (1<<j); 
		}
		// (i, x) 
		r[x] = (w[x-1]-w[i])*hh;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		cout << l[i] << ' ' << r[i] << '\n'; 
		ans = max(l[i]+r[i], ans);
	}
	cout << ans << '\n';

	return 0;
}






