#include <bits/stdc++.h>
using namespace std;

int p, q;

void solve(){
	cin >> p >> q;
	int S = 2*(2*q + p)+1;
	vector<int> V;
	for (int i = 2; i*i <= S; i++){
		if (S % i == 0) V.push_back(i);
	} 
	// V contains all n's
	for (int i : V){
		int n = (i-1)/2;
		int m = (S/i-1)/2;
		if (q <= n*(m+1)){
			cout << n << ' ' << m << '\n';
			return;
		}
	}
	cout << -1 << '\n';
	return ;
}

int main(){
	int t; cin >> t;
	while (t--) solve();
	return 0;
}