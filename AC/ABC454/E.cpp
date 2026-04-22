#include <bits/stdc++.h>
using namespace std;

int n, a, b;

void solve(){
	cin >> n >> a >> b;
	if (n % 2) {
		cout << "No\n";
		return;
	}
	if ((a + b) % 2 == 0){
		cout << "No\n";
		return ;
	}
	// even n and (a+b) being odd
	cout << "Yes\n";
	int pairsbefore = (a-1)/2;
	for (int i = 1; i <= pairsbefore; i++){
		for (int j = 1; j < n; j++) cout << "R";
		cout << "D";
		for (int j = 1; j < n; j++) cout << "L";
		cout << "D";
	}
	bool toggle = 0;
	for (int j = 1; j < b; j++){
		if (toggle==0){
			cout << "DR";
		} else {
			cout << "UR";
		}
		toggle = !toggle;
	}
	for (int j = b+1; j <= n; j++){
		if (toggle==0){
			cout << "RD";
		} else {
			cout << "RU";
		}
		toggle = !toggle;
	}
	int pairsafter = n/2-((a-1)/2+1);
	for (int i = 1; i <= pairsafter; i++){
		cout << "D";
		for (int j = 1; j < n; j++) cout << "L";
		cout << "D";
		for (int j = 1; j < n; j++) cout << "R";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) solve();

	return 0;
}