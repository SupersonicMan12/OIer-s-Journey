#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n;
int a[500005];
int f[500005], ans[500005];

int main(){
	int t; cin >> t; while (t--){
		cin >> n;
		for (int i = 1; i < n; i++){
			cin >> a[i]; 
		}
		f[1] = 1;
		// number of ways to get [1,i]
		for (int i = 2; i <= n; i++){
			f[i] = 1LL*f[i-1]*((i-1)-a[i-1])%MOD;
		}
		// permutation of k ops
		// k+1 nodes
		ans[0] = 0;
		for (int i = 1; i <= n-1; i++){
			ans[i] = (1LL*ans[i-1]*i%MOD + ((a[i]==0)*f[i]))%MOD;
		}
		for (int i = 1; i <= n-1; i++){
			cout << ans[i] << ' ';
		}
		cout << '\n';
	}


	return 0;
}