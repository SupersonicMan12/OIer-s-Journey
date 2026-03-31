#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int n;
int a[200005];
int lc[200005], rc[200005], sz[200005];
int stk[200005];
int dp[200005];
int fact[500005], inv[500005], ifact[500005];

void predfs(int x){
	sz[x] = 1;
	if (lc[x]){
		predfs(lc[x]);
		sz[x] += sz[lc[x]];
	}
	if (rc[x]){
		predfs(rc[x]);
		sz[x] += sz[rc[x]];
	}
}

long long comb(int x, int y){
	long long ans = 1LL * fact[x] * ifact[y] % MOD * ifact[x-y] % MOD;
	return ans;
}

void dfs(int x, bool left, bool right){
	if (lc[x]) dfs(lc[x], left, 1);
	if (rc[x]) dfs(rc[x], 1, right);
	int l = sz[lc[x]], r = sz[rc[x]];
	long long factor = comb(l+r, l);
	if (left && right){
		factor = (comb(l+r+1, l+1) + comb(l+r+1, l) + MOD - comb(l+r, l)) % MOD;
	} else if (left){
		factor = comb(l+r+1, l+1);
	} else if (right){
		factor = comb(l+r+1, l);
	}
	dp[x] = 1LL * dp[lc[x]] * dp[rc[x]] % MOD * factor % MOD;
}

int main(){
	fact[0] = fact[1] = 1; 
	ifact[0] = ifact[1] = inv[1] = 1;
	for (int i = 2; i <= 500000; i++){
		fact[i] = 1LL * fact[i-1] * i % MOD;
		inv[i] = 1LL * (MOD - MOD/i) * (inv[MOD%i]) % MOD;
		ifact[i] = 1LL * inv[i] * ifact[i-1] % MOD;
	}
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int top = 0;
	for (int i = 1; i <= n; i++){
		bool mark = 0;
		while (top > 0 && a[i] > a[stk[top]]) {
			top--; 
			mark = 1;
		}
		if (top) rc[stk[top]] = i;
		if (mark) lc[i] = stk[top+1];
		stk[++top] = i;
	}
	sz[0] = 0; dp[0] = 1;
	predfs(stk[1]);
	dfs(stk[1],0,0);
	cout << dp[stk[1]] << '\n'; 
	return 0;
}