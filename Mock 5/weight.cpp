#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int CAP = 40;
long long q,l,r,k;
// which place? how many edits remaining?
int dp[CAP][CAP*2];
int state[CAP], stateq[CAP];

void calc(long long x, int a[]){
	long long pow = 1;
	for (int i = 1; i < CAP; i++) {
		pow *= 3; 
		a[i] = 1;
	}
	for (int i = CAP-1; i >= 0; i--){
		if (x < 0){
			if (x <= -pow){
				x += pow;
				a[i] = 0;
			} else if (x < -(pow/2)){
				x += pow;
				a[i] = 0;
			} 
		} else if (x > 0) {
			if (x >= pow){
				x -= pow;
				a[i] = 2;
			} else if (x > pow/2) {
				x -= pow;
				a[i] = 2;
			} 
		} 
		pow /= 3;
	}
}

long long qry(long long x, long long k){
	long long ans = 0, exist = 0;
	calc(x);
	for (int i = CAP-1; i >= 0; i--){
		for (int st = 0; st < state[i]; st++){
			if (st != stateq[i]){
				long long rem = k - abs(stateq[i]-st) - exist;
				if (rem >= 0) ans += dp[i][rem];
			}
		}
		// now consider state[i]: ceiling:

    	

		exist += abs(state[i]-stateq[i]);
	}
	return ans;
}

int main(){
	int T; cin >> T;
	while (T--){
		cin >> q >> l >> r >> k;
		calc(q);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		dp[0][1] = (state[0]==1)?2:1;
		dp[0][2] = (state[0]==1)?0:1;

		if (k >= 2*CAP) k = 2*CAP-1;
		for (int i = 1; i < CAP; i++){
			for (int rem = 0; rem < 2*CAP; rem++){
				if (state[i]==1){
					if (rem >= 1) (dp[i][rem] += dp[i-1][rem-1])%=MOD;
					if (rem >= 1) (dp[i][rem] += dp[i-1][rem-1])%=MOD;
					(dp[i][rem] += dp[i-1][rem])%=MOD;
				} else {
					if (rem >= 2) (dp[i][rem] += dp[i-1][rem-2])%=MOD;
					if (rem >= 1) (dp[i][rem] += dp[i-1][rem-1])%=MOD;
					(dp[i][rem] += dp[i-1][rem])%=MOD;
				}
			}
		}

		for (int i = 0; i < CAP; i++){
			for (int rem = 1; rem < 2*CAP; rem++){
				(dp[i][rem] += dp[i][rem-1])%=MOD;
			}
		}

		memcpy(stateq, state, sizeof(state));
		cout << (qry(r+1,k)-qry(l,k)+MOD)%MOD << '\n';
	}

	return 0;
}





