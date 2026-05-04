#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int c[10005];
bool swapped;
int ans[104][104];

void output(){
	cout << "YES\n";
	if (swapped){
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				cout << ans[j][i] << ' ';
			}
			cout << '\n';
		}
	} else {
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cout << ans[i][j] << ' ' ; 
			}
			cout << '\n';
		}
	}
}

void solve(){
	cin >> n >> m >> k;
	
	swapped = (n>m);
	if (swapped) swap(n, m);

	bool f3=1, f4=1;
	for (int i = 1; i <= k; i++){
		cin >> c[i];
		if (c[i] != 1) f4 = 0;
		if (c[i] != min(n,m)) f3 = 0;
	}
	if (k == 1){
		if (c[1]==min(m,n)){
			cout << "YES\n";
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= m; j++){
					cout << 1 << ' ';
				}
				cout << '\n';
			}
		} else {
			cout << "NO\n";
		}
		return;
	} else if (f3){
		if (k > m){
			cout << "NO\n";
			return;
		}
		for (int i = 1; i <= k; i++){
			for (int j = 1; j <= n; j++){
				ans[j][(j+i-1-1)%m+1] = i;
			}
		}
		for (int i = k+1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				ans[j][(j+i-1-1)%m+1] = k;
			}
		}
		output();
		return;
	} else if (f4){
		if (k < n || k > n*m){
			cout << "NO\n";
			return;
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++) ans[i][j] = 0;
		}
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n && (i-1)*n+j <= k; j++){
				ans[j][i] = (i-1)*n+j;
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (!ans[i][j]) ans[i][j] = ans[i][j-1];
			}
		}
		output();
		return;
	} else {
		if (k > (n+m)/2) {
			cout << "NO\n"; 
			return;
		}
	}
}

int main(){
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}