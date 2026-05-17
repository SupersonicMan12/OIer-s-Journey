#include <bits/stdc++.h>

using namespace std;

const int N = 500005;
const long long MOD = 1000000007LL;
const int INF = 1e9;
int n;
long long x[N], r[N];
int L[N], R[N], nL[N], nR[N];
int mn[N << 2], mx[N << 2];

void build(int o, int l, int r){
	if (l == r){
		mn[o] = L[l];
		mx[o] = R[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(o << 1, l, mid);
	build(o << 1 | 1, mid + 1, r);
	mn[o] = min(mn[o << 1], mn[o << 1 | 1]);
	mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
}

int qmin(int o, int l, int r, int ql, int qr){
	if (ql <= l && r <= qr) return mn[o];
	int mid = (l + r) >> 1;
	int ans = INF;
	if (ql <= mid) ans = min(ans, qmin(o << 1, l, mid, ql, qr));
	if (qr > mid) ans = min(ans, qmin(o << 1 | 1, mid + 1, r, ql, qr));
	return ans;
}

int qmax(int o, int l, int r, int ql, int qr){
	if (ql <= l && r <= qr) return mx[o];
	int mid = (l + r) >> 1;
	int ans = -INF;
	if (ql <= mid) ans = max(ans, qmax(o << 1, l, mid, ql, qr));
	if (qr > mid) ans = max(ans, qmax(o << 1 | 1, mid + 1, r, ql, qr));
	return ans;
}





