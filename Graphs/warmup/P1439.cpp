#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005], b[100005];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		b[x] = i;
	}
	for (int i = 1; i <= n; i++){
		a[i] = b[a[i]];
	}
	// run LIS on a
	vector<int> V;
	for (int i = 1; i <= n; i++){
		int l = lower_bound(V.begin(), V.end(), a[i])-V.begin();
		if (l < (int)V.size()) V[l] = a[i];
		else V.push_back(a[i]);
	}
	cout << V.size() << '\n';

	return 0;
}