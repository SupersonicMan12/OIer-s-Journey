#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int l[1005];
// at disk i: the time that holds score j!
int dp[1005][1005];

int main(){
    cin >> n >> t >> m;
    for (int i = 1; i <= n; i++) cin >> l[i];
    memset(dp, 0x7f, sizeof(dp));
    dp[1][0] = 0;
    for (int d = 1; d <= n; d++){
        for (int i = m; i >= 1; i--){
            for (int j = n; j >= 0; j--){
                // this state is suboptimal or impossible
                if (dp[i][j]>t) continue;

                // add to disk
                if (dp[i][j]+l[d] <= t) dp[i][j+1] = min(dp[i][j+1],dp[i][j]+l[d]);

                // new disk
                dp[i+1][j+1] = min(dp[i+1][j+1], l[d]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if (dp[i][j] <= t){
                ans = max(ans, j);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}