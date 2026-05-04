#include <bits/stdc++.h>
using namespace std;

int n;
int Q[505], rk[505];
int R[505];
int where[505];
vector<int> ans;

void swp(){
	ans.push_back(2);
	swap(R[1], R[2]);
}

void rot(){
	ans.push_back(1);
	int last = R[n];
	for (int k = n; k > 1; k--){
		R[k] = R[k-1];
	}
	R[1] = last;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cout << 2 << endl;
	cout << n << ' ';
	for (int i = 1; i < n; i++) cout << i << ' ';
	cout << endl;
	cout << 2 << ' ' << 1 << ' ';
	for (int i = 3; i <= n; i++) cout << i << ' ';
	cout << endl;

	for (int i = 1; i <= n; i++) {
		cin >> Q[i];
		where[Q[i]] = i;
		R[i] = i;
	}
	for (int pass = 1; pass <= (n-1); pass++){
		rot();
		for (int i = 1; i <= n-1; i++) {
			rot();
			if (where[R[1]] > where[R[2]]) swp();
		}
	}

	cout << ans.size() << ' ';
	for (int v : ans){
		cout << v << ' ';
	}
	cout << endl;

	return 0;
}




