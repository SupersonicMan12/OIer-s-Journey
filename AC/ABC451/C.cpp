#include <bits/stdc++.h>
using namespace std;

int q;
priority_queue<int,vector<int>, greater<int>> P;

int main(){
	cin >> q;
	for (int i = 1; i <= q; i++){
		int op, x; cin >> op >> x;
		if (op == 1){
			P.push(x);
		} else {
			while (!P.empty() && P.top() <= x) P.pop();
		}
		cout << P.size() << '\n';
	}

	return 0;
}