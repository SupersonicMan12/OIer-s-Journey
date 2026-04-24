#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n;
int l[100005], r[100005];
long long w[100005], h[100005];
int ord[100005];

bool cmp(int x, int y){
	return h[x] > h[y];
}

int c2(int x){
	return 1LL*x*(x-1)/2%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n ;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		l[i] = i-1;
		r[i] = i+1;
		ord[i] = i;
	}
	long long ans = 0;
	h[0] = h[n+1] = -1;
	sort(ord+1, ord+n+1, cmp);
	for (int i = 1; i < n; i++){
		int x = ord[i];
		// if same height merge
		if (h[x] == h[r[x]]){
			(w[r[x]] += w[x])%=MOD;
			r[l[x]] = r[x];
			l[r[x]] = l[x];
			continue;
		}
		int best = max(h[l[x]], h[r[x]]);
		(ans += 1LL*c2(w[x]+1)*(c2(h[x]+1)-c2(best+1)+MOD)%MOD)%=MOD;
		if (h[r[x]]==best) {
			(w[r[x]] += w[x])%=MOD;
		} else {
			(w[l[x]] += w[x])%=MOD;
		}
		r[l[x]] = r[x];
		l[r[x]] = l[x];
	}
	(ans += 1LL*c2(w[ord[n]]+1)*c2(h[ord[n]]+1)%MOD)%=MOD;
	cout << ans << '\n';

	return 0;
}

