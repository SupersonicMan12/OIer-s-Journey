#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = ((-a[i]-i)%m +m)%m;
	}
	int len = 1;
	for (int i = 2; i <= n; i++){
		if (a[i]==(a[i-1]-1+m) % m) len++;
		else len = 1;
		if (len >= m) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	int t; cin >> t;
	while (t--) solve();
	return 0;
}