#include <bits/stdc++.h>
using namespace std;

int n, k;

void solve(){
	cin >> n >> k;
	int X = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int a; cin >> a;
			if ((i+j)%2){
				X = X^(a%(k+1));
			}
		}
	}
	if (X==0) cout << "Bob\n";
	else cout << "Alice\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while(T--) solve();
	return 0;
}