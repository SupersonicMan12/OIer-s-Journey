#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, q;
vector<int> L[200005];
vector<int> R[200005];
int mn2[200005];

void upd(int x, int &a, int &b){
	if (x < a) b = a, a = x;
	else if (x < b) b = x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int l, r; cin >> l >> r;
		L[r].push_back(l);
		R[l].push_back(r);
	}
	int a = INF, b = INF;
	for (int i = n; i >= 1; i--){
		for (int r : R[i]){
			upd(r, a, b);
		}
		mn2[i] = b;
	}
	for (int i = 1; i <= n; i++){
		L[i].push_back(0);
		L[i].push_back(n+1);
		sort(L[i].begin(), L[i].end());
		R[i].push_back(0);
		R[i].push_back(n+1);
		sort(R[i].begin(), R[i].end());
	}
	cin >> q;
	for (int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		bool flag = 0;
		int hit = *lower_bound(R[l].begin(), R[l].end(), r);
		if (hit == r && mn2[l]<=r){
			flag = 1;
		}
		int lreach = *(--lower_bound(R[l].begin(), R[l].end(), r));
		int rreach = *upper_bound(L[r].begin(), L[r].end(), l);
		if (lreach+1 >= rreach) flag = 1;
		if (flag) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}