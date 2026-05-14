#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
int a[500005];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		int x; cin >> x; a[x] = i;
	}
	int frontier = 0;
	long long ans = 0;
	int i;
	for (i = 1; i <= n; i++){
		if (a[i] != i) break;
		frontier = a[i];
		ans += (n-frontier);
	}
	if (i == n+1) ans++; 
	ans %= MOD;
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}