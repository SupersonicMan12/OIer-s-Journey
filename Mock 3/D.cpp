#include <bits/stdc++.h>
using namespace std;
const int NINF = -2e9;
long long n, A,B,C,D;
int a[100005];
// maximize
long long dp[100005];
int cnt[100005];



void s1(){
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = NINF;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++){
		int mn = 1000000, mx = 0, mex = 0; 
		for (int j = 0; j <= 105; j++) cnt[j]=0;
		for (int j = i; j >= 1; j--){
			mn = min(mn, a[j]);
			mx = max(mx, a[j]);
			cnt[a[j]]++;
			while (cnt[mex]) mex++;
			dp[i] = max(dp[i], dp[j-1] + A*mx + B*mn + C*mex + D);
		}
	}
	cout << dp[n] << '\n';
}


void s2(){
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){

	}
}

void solve(){
	cin >> n;
	cin >> A >> B >> C >> D;
	if (n <= 100) s1();
	if (A==0 && C==0) s2();
	if (B==0 && C==0) s3();
}

int main(){
	freopen("mix.in", "r", stdin);
	freopen("mix.out", "w", stdout);
	int t; cin >> t;
	while (t--) solve();

	return 0;
}