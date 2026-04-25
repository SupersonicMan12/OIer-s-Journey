#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[15];

void solve(){
	cin >> n;
	bool ans = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i]==100) ans = 1;
	}
	if (ans) cout << "Yes\n";
	else cout << "No\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) solve();
	return 0;
}