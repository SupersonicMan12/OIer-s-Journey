#include <bits/stdc++.h>
using namespace std;

int n, q, x;
long long a[100005];
long long s[100005];

int main(){
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = s[i-1]+a[i];
	}
	while (q--){
		long long ans = 0;
		cin >> x;
		int R = n;
		while (R && a[R] > x) R--;
		int r = R;
		// r is maintained as largest such that [l, r] works.
		for (int l = R; l >= 1; l--){
			if (r > l) ans += (s[r]-s[l])-a[l]*(r-l);
			if (l==1) break;
			// even case
			if ((r-l)%2){
				if (r+1 <= n && a[l-1]+a[r+1] <= x) r++;
			} else {
				if (a[l-1]+a[r] <= x) {
					if (r+1 <= n && a[r+1] <= x) r++;
				} else {
					r--;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}