#include <bits/stdc++.h>
using namespace std;

int n, m;
int f[105];
int cnt[105];

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> f[i];
		cnt[f[i]]++;
	}
	bool a1 = 1, a2 = 1;
	for (int i = 1; i <= m; i++){
		if (cnt[i]==0) a2 = 0;
		if (cnt[i] > 1) a1 = 0;
	}
	if (a1) cout << "Yes\n";
	else cout << "No\n";
	if (a2) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}