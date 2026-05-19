#include <bits/stdc++.h>
using namespace std;

long long dp[101][35005];
int opt[35005];
int a[35005];
int tmp[35005];
int prv[35005], nxt[35005];
int mn[35005], mx[35005];
int n, k, l, r;
long long C;

void add(int x){
	C -= (mx[a[x]]-mn[a[x]]);
	if (x > mx[a[x]] || mx[a[x]] == -1) {
		mx[a[x]] = x;
	}
	if (x < mn[a[x]] || mn[a[x]] == -1) {
		mn[a[x]] = x;
	}
	C += (mx[a[x]]-mn[a[x]]);
}

void remove(int x, bool right){
	C -= (mx[a[x]]-mn[a[x]]);
	if (!right){
		// left case
		if (nxt[x] && nxt[x] <= r){
			mn[a[x]] = nxt[x];	
		} else {
			mn[a[x]] = -1;
			mx[a[x]] = -1;
		}
	} else {
		// right case
		if (prv[x] && prv[x] >= l){
			mx[a[x]] = prv[x];
		} else {
			mn[a[x]] = -1;
			mx[a[x]] = -1;
		}
	}
	C += (mx[a[x]]-mn[a[x]]);
}

long long cost(int L, int R){
	while (l > L) add(--l);
	while (r < R) add(++r);
	while (l < L) remove(l++, 0);
	while (r > R) remove(r--, 1);
	return C;
}

void DC(int l, int r, int opl, int opr, int i){
	if (l > r) return;
	int mid = (l+r)>>1;
	for (int x = opl; x <= min(opr, mid-1); x++){
		// cout << x+1 << ' ' << mid << ' ' << cost(x+1, mid) << endl;
		long long cand = dp[i-1][x]+cost(x+1, mid);
		if (dp[i][mid] > cand){
			dp[i][mid] = cand;
			opt[mid] = x;
		}
	}
	if (l == r) return;
	DC(l, mid-1, opl, opt[mid], i);
	DC(mid+1, r, opt[mid], opr, i);
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++){
		prv[i] = tmp[a[i]];
		tmp[a[i]] = i;
	}
	memset(tmp, 0, sizeof(tmp));
	for (int i = n; i >= 1; i--){
		nxt[i] = tmp[a[i]];
		tmp[a[i]] = i;
	}
	memset(mn, -1, sizeof(mn));
	memset(mx, -1, sizeof(mx));
	for (int i = 1; i <= n; i++) add(i);
	l = 1, r = n;
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= k; i++){
		DC(1, n, 0, n-1, i);
	}
	cout << dp[k][n] << endl;
	return 0;
}