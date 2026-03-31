#include <bits/stdc++.h>
using namespace std;

long long n,k,l;
int a[200005];

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> k >> l;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a+1,a+n+1);
		long long rng = a[n]-a[1];
		long long first = 0;
		long long crit = max(l-a[n], a[1]-0);
		// difference array in a2-n
		for (int i = n; i >= 2; i--){
			a[i] -= a[i-1];
		}
		sort(a+2,a+n+1, greater<int>());
		long long ans = first+crit+1LL*(k-1)*(l-rng);
		for (int i = 2; i <= min(n,k+1); i++){
			rng -= a[i];
			first += a[i]/2;
			crit += a[i]/2;
			ans = max(ans, first+crit+1LL*(k-i)*(l-rng));
		}
		cout << ans << '\n';
	}

	return 0;
}