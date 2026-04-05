#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[400005];
int appear[200005];

void solve(){
	cin >> n;
	vector<int> V;
	int curr = 1;
	for (int i = 1; i <= 2*n; i++){
		cin >> a[i];
		if (!appear[a[i]]) {
			appear[a[i]] = curr;
		} else {
			if (curr == appear[a[i]]) {
				curr = 3-curr;
				V.push_back(i-1);
			}
		}
	}
	cout << V.size() << '\n';
	for (auto v: V){
		cout << v << ' ';
	}
	cout << '\n';
	for (int i = 1; i <= n; i++){
		appear[i] = 0;
	}
}

int main(){
	cin >> t;
	while (t--) solve();
	return 0;
}