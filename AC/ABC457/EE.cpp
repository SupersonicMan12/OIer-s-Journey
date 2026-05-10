#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<int> L[200005];
vector<int> R[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int l, r; cin >> l >> r;
		L[r].push_back(l);
		R[l].push_back(r);
	}
	for (int i = 1; i <= n; i++){
		if (!L[i].empty()) {
			L[i].push_back(n+1);
			sort(L[i].begin(), L[i].end());
		}
		if (!R[i].empty()) {
			R[i].push_back(0);
			sort(R[i].begin(), R[i].end());
		}
	}
	cin >> q;
	for (int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		if (R[l].empty() || L[r].empty()) {
			cout << "No\n"; continue;
		}
		int rreach = *lower_bound(L[r].begin(), L[r].end(), l);
		int lreach = *(--upper_bound(R[l].begin(), R[l].end(), r));
		if (rreach <= lreach+1){
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}