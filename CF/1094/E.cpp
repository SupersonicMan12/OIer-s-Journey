#include <bits/stdc++.h>
using namespace std;

int t, n, tmp;
long long a[200005];
int p[200005];

bool qry(long long x){
	cout << "Q " << x << endl;
	cin >> tmp; 
	return tmp;
}

void solve(){
	cin >> n;
	cout << 0 << endl;
	cout << "I " << 0 << endl; 
	cin >> tmp;
	if (tmp == 1){
		// and 
		int sz = 1;
		long long c = 0;
		for (int i = 0; i < n; i++){
			cout << "I " << (1LL<<i) << endl;
			cin >> tmp;
			if (tmp > sz) c += (1LL<<i);
			sz = tmp;
		}
		cout << "A " << 1 << ' ' << c << endl;
	} else {
		// xor or
		long long l = 1, r = (1LL<<n)-1;
		while (l < r){
			long long mid = (l+r+1)>>1;
			if (qry(mid)) l = mid;
			else r = mid-1;
		}
		long long c = l;
		long long b = c&(-c);
		if (c == b){
			// not big enough take max
			long long mask = (1LL<<n)-1;
			cout << "I " << mask << endl;
			cin >> tmp;
			cout << "Q " << mask << endl;
			cin >> tmp;
			if (tmp > 0) {
				cout << "A " << 2 << ' ' << c << endl;
			} else {
				cout << "A " << 3 << ' ' << c << endl;
			}
		} else {
			cout << "I " << b << endl;
			cin >> tmp;
			if (tmp > 2) {
				cout << "A " << 3 << ' ' << c << endl;
			} else {
				cout << "A " << 2 << ' ' << c << endl;
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) solve();
	return 0;
}