#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];
struct node{
	int last, first, idx;
	bool operator<(const node& other) const{
		if (last != other.last) return last < other.last;
		if (first != other.first) return first < other.first;
		return idx < other.idx;
	}
} row[200005];
int c[200005];

int main(){
	cin >> n >> m;
	vector<int> V(n+1);
	for (int i = 1; i <= n+1; i++){
		cin >> a[i];
		row[i].idx = i;
		row[i].last = a[i];
		V[i-1] = a[i];
	}
	sort(V.begin(), V.end());
	for (int i = 1; i <= n+1; i++){
		row[i].first = V[i-1];
	}
	sort(row+1, row+n+2);
	// for (int i = 1; i <= n+1; i++){
	// 	c[i] = i;
	// }
	vector<int> ans;
	int curr = row[1].idx;
	for (int i = 1; i <= n; i++){
		ans.push_back(V[curr-1]);
		curr = row[curr].idx;
	}
	for (int v : ans) cout << v << ' ';
	cout << endl;
	return 0;
}


