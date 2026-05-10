#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long l[200005];
vector<long long> G[200005];
long long c[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> l[i];
		for (int j = 1; j <= l[i]; j++){
			long long x; cin >> x; 
			G[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++){
		cin >> c[i]; 
	}
	int i;
	for (i = 1; i <= n; i++){
		if (k <= c[i]*l[i]) break;
		k -= c[i]*l[i];
	} 
	k--;
	cout << G[i][k%l[i]] << endl;

	return 0;
}
