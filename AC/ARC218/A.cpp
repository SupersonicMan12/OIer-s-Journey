#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n, m;
int a[505][505];
int off[250005][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			off[a[i][j]][i]++;
		}
	}

	long long topp = 1;
	for (int i = 1; i <= n; i++){
		(topp = topp*m)%=MOD;
	}
	long long ans = 0;
	for (int i = 1; i <= n*m; i++){
		long long add = 1;
		for (int j = 1; j <= n; j++){
			(add = add*(m-off[i][j]))%=MOD;
		}
		(ans += (topp-add+MOD)%MOD) %= MOD;
	}
	cout << ans << '\n';


	return 0;
}