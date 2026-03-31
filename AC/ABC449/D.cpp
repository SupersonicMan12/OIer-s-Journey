#include <bits/stdc++.h>
using namespace std;

// finds [0,x] * [0,y]
long long psum(int x, int y){
	if (x<y) swap(x, y);

	if (y%2) y--;
	int k = (y+2)/2;
	long long ans = 1LL*(k-1)*k*2+k;
	if ((x-(y+1))%2 == 0){
		if ((x%2==0)){
			ans += 1LL*(x-y)/2*(y+1);
		} else {
			ans += 1LL*(x-y-2)/2*(y+1);
		}
	} else {
		ans += 1LL*(x-(y+1))/2*(y+1);
	}
	return ans;
}

int main(){
	int l,r,d,u;
	cin >> l >> r >> d >> u;
	int xx = 0-min(l, d);
	if (xx % 2){
		if (xx < 0) xx--;
		else xx++;
	}
	l += xx, r += xx;
	d += xx, u += xx;
	cout << psum(r,u)-psum(r,d-1)-psum(l-1,u)+psum(l-1,d-1) << endl;

	return 0;
}