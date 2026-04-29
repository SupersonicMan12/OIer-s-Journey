#include <bits/stdc++.h>
using namespace std;

int n, cnt, p; long long x, bit;
int t[3200000][2];

int main(){
	cin >> n;
	cin >> x;
	bit = (1LL<<30);
	p = 0;
	while (bit > 0){
		bool is = ((x & bit)>0);
		if (!t[p][is]) t[p][is] = ++cnt;
		p = t[p][is];
		bit >>= 1;
	}
	long long ans = 0;
	for (int i = 2; i <= n; i++){
		cin >> x;
		// first try x:
		bit = (1LL<<30);
		long long best = 0;
		p = 0;
		while (bit > 0){
			bool is = ((x & bit)>0);
			if (t[p][is^1]) {
				p = t[p][is^1];
				best |= bit;
			} else {
				p = t[p][is];
			}
			bit >>= 1;
		}
		ans = max(ans, best);

		// construct x:
		bit = (1LL<<30);
		p = 0;
		while (bit > 0){
			bool is = ((x & bit)>0);
			if (!t[p][is]) t[p][is] = ++cnt;
			p = t[p][is];
			bit >>= 1;
		}
	}
	cout << ans << '\n';

	return 0;
}