#include <bits/stdc++.h>
using namespace std;
const int space = 5;

int main(){
	int x; cin >> x;
	int lim = (1<<space);
	for (int y = 1; y < lim; y++){
		int cnt = 0;
		for (int i = 0; i < lim; i++){
			if (((x+i) & (y+i)) == (x+i)){
				cnt++;
			}
		}
		cout << y << ':' << cnt << '\n';
	}
	
	return 0;
}

// from this aj-ai 's number of 1's,
// notice the difference cycle is equivalent to 0 (aj-ai)
// each extra 1 cuts half the same