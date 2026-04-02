// P3287 on Luogu
#include <bits/stdc++.h>
using namespace std;

int n, k, a[10005];
// dp[pos][takes]
int f[10005][505];
int maxx, maxy;
int t[505][5505];

int pmax(int x, int y){
	x++;
	int ret = 0;
	for (int i = x; i; i -= i&(-i)){
		for (int j = y; j; j -= j&(-j)){
			ret = max(ret, t[i][j]);
		}
	}
	return ret;
}

void add(int x, int y, int val){
	x++;
	for (int i = x; i <= maxx; i += i&(-i)){
		for (int j = y; j <= maxy; j += j&(-j)){
			t[i][j] = max(t[i][j], val);
		}
	}
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		maxy = max(a[i], maxy);
	}
	maxx = k+1; maxy += k;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= k ; j++){
			f[i][j] = pmax(j, a[i]+j) + 1;
			ans = max(ans, f[i][j]);
		}
		// layering
		for (int j = 0; j <= k; j++){
			add(j, a[i]+j, f[i][j]);
		}
	}
	cout << ans << '\n';

	return 0;
}

// appendix: notice how it is possible to reduce to NK (log(Amax)+log(K)) rather than NK log Amax log K
// by noticing that when moving from j-1 to j, the only parts added to pmax are a single row and column,
// which would then be manageable within a single log
// this, however, passes still.


