#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];
int r[200005];

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n/2; i++){
		a[i] = (a[i]-a[n+1-i]+m)%m;
	}
	n = n/2;
	a[0] = 0;
	a[n+1] = 0;
	int ties = 0;
	long long S = 0;
	long long ans = 0;
	vector<int> decrease;
	vector<int> increase;
	for (int i = 1; i <= n+1; i++){
		int d = (a[i]-a[i-1]+m)%m;
		int dd = d-m;
		ans += min(d, m - d);
		if (abs(d) > abs(dd)){
			S += (d-m);
			increase.push_back(2*d-m);
		} else if (abs(d) < abs(dd)) {
			S += d;
			decrease.push_back(m-2*d);
		} else {
			ties++;
		}
	}	
	sort(decrease.begin(), decrease.end());
	sort(increase.begin(), increase.end());
	if (ties == 0){
		if (S > 0){
			long long need = S/m;
			for (int i = 0; i < need; i++) ans += decrease[i];
		} else if (S < 0){
			long long need = (-S)/m;
			for (int i = 0; i < need; i++) ans += increase[i];
		}
	} else {
		long long low = S-1LL*ties*m/2;
		long long high = S+1LL*ties*m/2;
		if (low > 0){
			long long need = low/m;
			for (int i = 0; i < need; i++) ans += decrease[i];
		} else if (high < 0){
			long long need = (-high)/m;
			for (int i = 0; i < need; i++) ans += increase[i];
		}
	}
	cout << ans/2 << '\n';
}

int main(){
	int t; cin >> t;
	while (t--) solve();

	return 0;
}