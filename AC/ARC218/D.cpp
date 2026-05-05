// WRONG SOLUTION IDEA!!

#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[200005];
int bad[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[n+1] = n+1;
	for (int i = 2; i < n; i++){
		bad[i] = bad[i-1]+(a[i]<a[i-1] && a[i]>a[i+1]);
	}
	for (int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		if (l == r){
			cout << 1 << '\n';
		} else if (r == l+1){
			if (a[l] < a[r]){
				cout << 2 << '\n';
			} else {
				cout << 1 << '\n';
			}
		} else {
			int ans = r-l+1-(bad[r-1]-bad[l]);
			if (a[r] < a[r-1]) ans--;
			if (a[l] > a[l+1]) ans--;
			cout << ans << '\n';
		}
	}
	return 0;
}