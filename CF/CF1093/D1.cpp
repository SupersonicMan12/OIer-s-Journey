#include <bits/stdc++.h>
using namespace std;

int n;

int lqry(int x){
	cout << "? " << x << ' ';
	for (int i = 1; i <= x; i++){
		cout << i << ' ';
	}
	cout << endl;
	int ans; cin >> ans;
	return ans;
}

int rqry(int x){
	cout <<"? " << n-x+1 << ' ';
	for (int i = x; i <= n; i++){
		cout << i << ' ';
	}
	cout << endl;
	int ans; cin >> ans;
	return ans;
}

int mqry(int l, int r, bool x, int p3){
	cout <<"? " << (r-l+1+x) << ' ';
	for (int i = l; i <= r; i++) cout << i << ' ';
	if (x) cout << p3 << ' ';
	cout << endl;
	int ans; cin >> ans;
	return ans;
}

void solve(){
	cin >> n;
	n = 2*n+1;
	int p1,p2,p3;
	int l = 2, r = n-1;
	while (l < r){
		int mid = (l+r)>>1;
		int q = rqry(mid);
		if ((n-mid+1-q)%2){
			l = mid+1;
		} else {
			r = mid;
		}
	}
	p1 = l-1;

	l = 3, r = n;
	while (l < r){
	    int mid = (l+r)>>1;
	    int q = lqry(mid);
	    if ((mid-q)%2) r = mid;
	    else l = mid+1;
	}
	p3 = l;

	l = p1+1, r = p3-1;
	while (l < r){
		int mid = (l+r)>>1;
		int q = mqry(p1, mid, 1, p3);
		if ((mid-p1+2-q)%2) r = mid;
		else l = mid+1;
	}
	p2 = l;

	cout << "! " << p1 << ' ' << p2 << ' ' << p3 << endl;
}

int main(){
	int t; cin >> t;
	while (t--) solve();
	return 0;
}