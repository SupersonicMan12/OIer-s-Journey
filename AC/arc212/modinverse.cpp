#include <bits/stdc++.h>
using namespace std;

int n;
const int MOD = 1000000007;
int inv[10000005];

int main(){
	cin >> n;
	inv[1] = 1;
	for (int i = 2; i <= n; i++){
		inv[i] = 1LL * (MOD-MOD/i) * inv[MOD%i] % MOD;
	}
	return 0;
}