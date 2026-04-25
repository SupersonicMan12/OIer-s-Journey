#include <bits/stdc++.h>
using namespace std;

int t, n;
long long a[200005];
int p[200005];

void solve(){
	cin >> n;
	vector<pair<long long, int>> V;
	a[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
		V.push_back({a[i-1], i});
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < n; i++){
		p[V[i].second] = n-i;
	}
	for (int i = 1; i <= n; i++){
		cout << p[i] << ' ';
	}
	cout << '\n';
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) solve();
	return 0;
}