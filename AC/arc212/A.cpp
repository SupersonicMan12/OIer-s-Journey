#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int k;

int main(){
	cin >> k;
	long long ans = 0;
	for (int x = 1; x <= k; x++){
		for (int y = 1; y+x < k; y++){
			int z = k-x-y; 
			// consider x, y, z:
			long long tmp = 1LL*(x-1)*(y-1)%MOD*(z-1)%MOD;
			tmp = (1LL * tmp * (x+y+z-max({x,y,z})))%MOD;
			ans = (ans+tmp)%MOD;
		}
	}
	cout << ans << '\n';
	return 0;
}