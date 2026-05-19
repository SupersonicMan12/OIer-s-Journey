#include <bits/stdc++.h>
using namespace std;

int main(){
	cout << 128 << ' ' << 896 << ' ' << 896 << endl;
	int curr = 0;
	for (int i = 1; i <= 128; i++){
		cout << curr << ' ';
		curr = (curr+7)%128;
	}
	cout << endl;
	return 0;
}

