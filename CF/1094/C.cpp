#include <bits/stdc++.h>
using namespace std;

const int NINF = -1e9;
int T, n, cnt;
int a[5005];
// best for ending at i with median j
int dp[5005][5005];
int t[5005];

void add(int x) {
    for (; x <= cnt; x += x & -x) 
    	t[x] ++;
}

int kth(int k) {
    int x = 0;
    for (int p = 1 << 12; p; p >>= 1) {
        int nx = x + p;
        if (nx <= cnt && t[nx] < k) {
            x = nx;
            k -= t[nx];
        }
    }
    return x + 1;
}

void solve(){
	cin >> n;
	set<int> S;
	map<int,int> M;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		S.insert(a[i]);
	}
	cnt = 0;
	for (auto u : S){
		M[u] = ++cnt;
	}
	//discretize into [1, cnt]
	for (int i =1 ; i <= n; i++){
		a[i] = M[a[i]];
	}

	for (int i = 0; i <= n; i++)
    for (int j = 1; j <= cnt; j++)
	dp[i][j] = NINF;

	for (int i = 1; i <= cnt; i++){
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; i++){
		memset(t, 0, sizeof(t));
		add(a[i]);
		int len = 1;
		int med = kth((len+1)/2);
		dp[i][med] = max(dp[i-1][med]+1, dp[i][med]);
		for (int j = i-3; j >= 0; j-=2){
			add(a[j+1]);
			add(a[j+2]);
			len+=2;
			int med = kth((len+1)/2);
			dp[i][med] = max(dp[j][med]+1, dp[i][med]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= cnt; i++){
		ans = max(dp[n][i], ans);
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) solve();
	return 0;
}