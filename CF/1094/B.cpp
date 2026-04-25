#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[100005];

void solve(){
	cin >> n >> m;
	vector<int> odd;
	vector<int> even;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		ans += a[i];
		if (i % 2) odd.push_back(a[i]);
		else even.push_back(a[i]);
	}
	sort(odd.begin(), odd.end(), greater<int>());
	sort(even.begin(), even.end(), greater<int>());
	int o = 0, e = 0;
	int omax = odd.size(), emax = even.size();
	for (int i = 1; i <= m; i++){
		int x; cin >> x;
		if (x%2 && o < omax) {
			if (!(o >= 1 && odd[o] < 0)) 
			ans -= odd[o++];
		}
		if ((x%2==0) && e < emax){
			if (!(e >= 1 && even[e] < 0)) 
			ans -= even[e++];
		} 
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) solve();
	return 0;
}