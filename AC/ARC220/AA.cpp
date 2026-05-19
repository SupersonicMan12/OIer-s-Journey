#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> P;

void answer(){
	cout << "Yes\n";
	while (!P.empty()){
		int x = P.top(); P.pop();
		cout << x << ' ';
	}
	cout << '\n';
}

void solve(){
	int n; cin >> n;
	while (!P.empty()) P.pop();
	if (n == 2 || n == 3 || n == 5){
		cout << "No\n";
		return;
	}
	
	if (n == 1){
		P.push(1);
		answer();
		return;
	}

	int curr;
	if (n % 3 == 1){
		P.push(2); P.push(2); P.push(2); P.push(2);
		curr = 4;
	} else if (n % 3 == 2){
		P.push(2); P.push(2); P.push(2); P.push(3);
		P.push(3); P.push(7); P.push(14); P.push(21);
		curr = 8;
	} else {
		P.push(2); P.push(2); P.push(2); P.push(3);
		P.push(3); P.push(6);
		curr = 6;
	}

	while (curr < n){
		int x = P.top(); P.pop();
		curr += 3;
		for (int i = 1; i <= 4; i++){
			P.push(x*2);
		}
	}
	answer();
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();

	return 0;
}