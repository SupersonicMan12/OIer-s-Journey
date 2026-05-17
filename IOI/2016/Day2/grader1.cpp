#include "painter.cpp"
#include <iostream>
#include <vector>

int main(){
	string s; cin >> s;
	vector<int> V;
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		int x; cin >> x; V.push_back(x);
	}
	cout << solve_puzzle(s, V) << endl;

	return 0;
}