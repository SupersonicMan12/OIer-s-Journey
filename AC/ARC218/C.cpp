#include <bits/stdc++.h>
using namespace std;

int n;
int Q[505];
int R[505];
int where[505];
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cout << n-1 << endl;
	for (int i = 2; i <= n; i++){
		// needs i-1 swaps
		cout << i << ' ';
		for (int j = 2; j <= i; j++){
			cout << j-1 << ' ';
		}
		for (int j = i+1; j <= n; j++){
			cout << j << ' ';
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		cin >> Q[i];
		R[i] = i;
		where[i] = i;
	}
	for (int i = n; i > 1; i--){
		int times = i-where[Q[i]];
		while (times--){
			ans.push_back(i-1);
			// a loop of first i;
			int last = R[i];
			for (int k = i; k > 1; k--){
				R[k] = R[k-1];
			}
			R[1] = last;
		}
		for (int j = 1; j <= i; j++){
			where[R[j]] = j;
		}
	}
	cout << ans.size() << ' ';
	for (int v : ans){
		cout << v << ' ';
	}
	cout << endl;

	return 0;
}




