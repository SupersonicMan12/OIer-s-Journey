#include <bits/stdc++.h>
using namespace std;

int n;
int a[205];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1, greater<int>());
	for (int i = 2; i <= n; i++){
		if (a[i]==a[i-1]) {
			cout << -1 << '\n';
			return;
		}
	}
	for (int i = 1; i <= n; i++){
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main(){
	int t; cin >> t;
	while (t--) solve();
	return 0;
}