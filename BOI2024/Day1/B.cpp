#include <bits/stdc++.h>
using namespace std;
typedef __int128 ii;
int n;
ii x[100005], y[100005];

void fix(int i, int j){
	// decrease y[i] by y[i]/y[j]*y[j] times
	ii amt = y[i]/y[j];
	y[i] -= y[j]*amt;
	x[i] -= x[j]*amt;
	if (y[i] == 0) return;
	fix(j,i);
}

ii myabs(ii x){
	return (x>=0)?x:-x;
}

int main(){
	cin >> n;
	if (n <= 2) {cout << -1 << endl; return 0;}
	int ym = 1;
	for (int i = 1; i <= n; i++){
		long long xx, yy; cin >> xx >> yy;
		x[i] = xx; y[i] = yy;
		if (y[i] < y[ym]) ym = i;
	}
	for (int i = 1; i <= n; i++){
		if (i==ym) continue;
		x[i] -= x[ym];
		y[i] -= y[ym];
	}
	x[ym]=y[ym]=0;
	swap(x[1], x[ym]);
	swap(y[1], y[ym]);
	for (int i = 2; i < n; i++){
		if (y[i]==0) continue;
		// help y[i] get to 0 with y[i+1]
		fix(i+1, i);
		if (y[i+1]==0) {
			swap(x[i],x[i+1]);
			swap(y[i],y[i+1]);
		}
	}
	ii g = myabs(x[2]);
	for (int i = 3; i < n; i++) {
		g = __gcd(g, myabs(x[i]));
	}
	if (g == 0 || y[n] == 0) {
		cout << -1 << endl;
	} else {
		cout << (long long)(g*myabs(y[n])) << endl;
	}

	return 0;
}


