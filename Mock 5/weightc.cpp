#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int CAP = 40;
long long q,l,r,k;
// which place? how many edits remaining?
int dp[CAP+3][2][2][CAP*2+3];
int state[CAP], stateq[CAP], pre[CAP];

void calc(long long x, int a[]){
	long long pow = 1; a[0] = 1;
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
	memset(dp, 0, sizeof(dp));
	calc(x, state);
	dp[CAP][1][1][0] = 1;
	for (int i = CAP-1; i >= 0; i--){
		for (int tight = 0; tight <= 1; tight++){
			for (int same = 0; same <= 1; same++){
				for (int cost = 0; cost < 2*CAP; cost++){
					int ways = dp[i+1][tight][same][cost];
                    if (!ways) continue;
                    for (int d = 0; d <= 2; d++){
                    	if (tight && d > state[i]) continue;
                    	int ntight = (tight && (d == state[i]));
                    	int nsame = (same && (d == stateq[i])), ncost;
                    	if (nsame){
                    		ncost = cost;
                    	} else if (same){
                    		ncost = pre[i]+(d != 1);
                    	} else {
                    		ncost = cost+(d!=1);
                    	}
                    	if (ncost > 2*CAP) continue;
                    	(dp[i][ntight][nsame][ncost] += ways)%=MOD;
                    }
				}
			}
		}
	}

	long long ans = 0;
	for (long long cost = 0; cost <= min(k, 2LL*CAP-1); cost++){
		for (int same = 0; same <= 1; same++){
			(ans += dp[0][0][same][cost])%=MOD;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("weight.in", "r", stdin);
	freopen("weight.out", "w", stdout);
	int T; cin >> T;
	while (T--){
		cin >> q >> l >> r >> k;
		calc(q, stateq);
		pre[0] = (stateq[0]!=1);
		for (int i = 1; i < CAP; i++){
			pre[i] = pre[i-1]+(stateq[i]!=1);
		}
		cout << (qry(r+1,k)-qry(l,k)+MOD)%MOD << '\n';
	}

	return 0;
}





