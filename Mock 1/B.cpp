#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
int a[6005], b[3005];
bool ca[6005], cb[6005];
bool op[3005];
int shoot[6005];
int occupied[6005];
int dp[6005][3005];
int n, jj;

int main(){
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	long long ans = 1;
	cin >> n;
	for (int i = 1; i <= 2*n; i++){
		cin >> a[i];
		if (a[i] && ca[a[i]]) ans = 0;
		ca[a[i]] = 1;
	}
	for (int i = 1; i <= n; i++){
		cin >> op[i];
	}
	// prework
	// duplicate detection still missing!
	for (int i = 1; i <= n; i++){
		cin >> b[i];
		if (b[i] && cb[b[i]]) {ans = 0; break;}
		cb[b[i]] = 1;
		if (a[i*2-1]==0 && a[i*2]==0){
			ans = (ans * 2)%MOD;
			shoot[b[i]] = op[i]?1:2;
			occupied[b[i]] = 1;
		} else if (a[i*2-1]==0){
			if (a[i*2] == b[i]){
				shoot[b[i]] = op[i]?1:2;
				occupied[b[i]] = 1;
			} else {
				if (op[i] && b[i]<a[i*2]){
					ans = 0;
				} else if (!op[i] && b[i]>a[i*2]){
					ans = 0;
				} else {
					occupied[a[i*2]] = 1;
					occupied[b[i]] = 1;
				}
			}
		} else if (a[i*2]==0){
			if (a[i*2-1] == b[i]){
				shoot[b[i]] = op[i]?1:2;
				occupied[b[i]] = 1;
			} else {
				if (op[i] && b[i]<a[i*2-1]){
					ans = 0;
				} else if (!op[i] && b[i]>a[i*2-1]){
					ans = 0;
				} else {
					occupied[a[i*2-1]] = 1;
					occupied[b[i]] = 1;
				}
			}
		} else {
			if (op[i] && max(a[i*2-1], a[i*2]) != b[i]) ans = 0;
			if (!op[i] && min(a[i*2-1], a[i*2]) != b[i]) ans = 0;
			occupied[a[i*2-1]] = 1;
			occupied[a[i*2]] = 1;
		}
	}
	for (int i = 1; i <= 2*n; i++){
		if (shoot[i] == 2) jj++;
	}
	if (ans == 0){
		cout << 0 << '\n';
		return 0;
	}

	int N = 2*n;
	int cnt = 0, vac = 0, fr = 0;
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++){
		// type A: shooting
		if (shoot[i]){
			if (shoot[i] == 1){
				for (int j = 0; j <= jj; j++){
					dp[i][j] = 1LL*dp[i-1][j]*max(vac-j-fr, 0)%MOD;
				}
				fr++;
			} else {
				cnt++;
				for (int j = 0; j <= jj; j++){
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		// type B: vacant element
		else if (!occupied[i]){
			vac++;
			for (int j = 0; j <= jj; j++){
				// do nothing and be a reserve, or get rid of a min shooter
				dp[i][j] = dp[i-1][j];
				if (j > 0) (dp[i][j] += 1LL*dp[i-1][j-1]*max(cnt-j+1,0)%MOD) %= MOD;
			}
		}
		// type C: occupied element
		else {
			for (int j = 0; j <= jj; j++){
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	
	ans = 1LL*ans * dp[N][jj] % MOD;
	cout << ans << '\n';

	return 0;
}


