#include <bits/stdc++.h>
using namespace std;

int n, q, x;
long long a[100005];

long long suma(int l, int r){
	if (l > r) return 0;
	int mid = (l+r)>>1;
	return a[mid]-a[l-1];
}

int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i]+=a[i-1];
	}
	while (q--){
		cin >> x;
		long long ans = 0;
		for (int i = 1; i <= n; i++){
			// consider the second half sum 
			// of [i, mid]
			// find first with sum >=
			// then [i, r] 
			// are all valid intervals
			int l = i, r = n+1;
			while (l < r){
				int mid = (l+r)>>1;
				if (suma(i,mid)>x) r = mid;
				else l = mid+1;
			}
			r--;
			ans += a[r]-a[i-1];
			ans -= 1LL*(a[i]-a[i-1])*(r-i+1);
		}
		cout << ans << '\n';
	}
	return 0;
}