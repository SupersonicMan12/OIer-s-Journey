#include <bits/stdc++.h>
using namespace std;

int h, w, q;
int ah, aw;

int main(){
	cin >> h >> w >> q;
	ah = h, aw = w;
	for (int i = 1; i <= q; i++){
		int type, x; cin >> type >> x;
		if (type == 1){
			// bottom r rows
			cout << x*aw << '\n';
			ah -= x;
		} else {
			cout << x*ah << '\n';
			aw -= x;
		}
	}
}