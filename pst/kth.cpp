#include <bits/stdc++.h>
using namespace std;

int n, m, c;
int a[100005], M[100005];
int root[100005];
int t[4000005];
int lc[4000005], rc[4000005];
pair<int,int> P[100005];

int update(int x, int l, int r, int q){
	if (l == r){
		t[++c] = t[x]+1;
		return c;
	}
	int mid = (l+r)>>1;
	int nx = ++c;
	if (q <= mid){
		lc[nx] = update(lc[x], l, mid, q);
		rc[nx] = rc[x];
	} else {
		lc[nx] = lc[x];
		rc[nx] = update(rc[x], mid+1,r, q);
	}
	t[nx] = t[lc[nx]] + t[rc[nx]];
	return nx;
}

int query(int jr, int sr, int l, int r, int k){
	if (l == r) return l;
	int mid = (l+r)>>1;
	int curr = t[lc[sr]]-t[lc[jr]];
	if (k <= curr)  return query(lc[jr], lc[sr], l, mid, k);
	else            return query(rc[jr], rc[sr], mid+1, r, k-curr);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		P[i] = {a[i], i};
	}
	sort(P+1, P+n+1);
	for (int i = 1; i <= n; i++){
		M[i] = P[i].first;
		a[P[i].second] = i;
	}
	for (int i = 1; i <= n; i++){
		root[i] = update(root[i-1], 1, n, a[i]);
	}
	for (int i = 1; i <= m; i++){
		int x, y, k; cin >> x >> y >> k;
		cout << M[query(root[x-1], root[y], 1, n, k)] << '\n';
	}
	return 0;
}


