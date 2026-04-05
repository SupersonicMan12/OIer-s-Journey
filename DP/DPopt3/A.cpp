#include <bits/stdc++.h>
using namespace std;

int n;

void solve(){
	cin >> n;
	int g = n/4;
	for (int i = 1; i <= g; i++){
		int base = (i-1)*4+1;
		cout << base << ' ' << base+2 << ' ' << base+1 << ' ' << base+3;
		if (i != g || n % 4 != 0) cout << ' ';
	}
	if (n % 4 == 1){
		cout << n << '\n';
	} else if (n %4 ==2){
		cout << n-1 << ' ' << n << '\n';
	} else if (n% 4 == 3){
		cout << n-2 << ' ' << n << ' ' << n-1 << '\n';
	} else {
		cout << '\n';
	}
}

int main(){
	int t; cin >> t; 
	while (t--) solve();

	return 0;
}