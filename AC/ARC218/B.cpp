#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	vector<int> V;
	int prev = 0;
	for (int i = 1; i <= n; ){
		int v = a[i];
		int j = i;
		while (j <= n && a[j] == v) j++;
		if (v-prev>0) V.push_back(v-prev);
		V.push_back(j-i);
		prev = v;
		i = j;
	}
	bool win = 0;
	for (int i = (int)V.size()-1; i >= 0; i--){
		if (V[i]==1) win = !win;
		else win = 1;
	}
	if (win) cout << "Alice\n";
	else cout << "Bob\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}