#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tiii;
int n, m, cnt;
pair<int,int> a[100005];
int root[100005];
int t[2000005], lc[2000005], rc[2000005];
int lh[2000005], rh[2000005];

int add(int x, int l, int r, int q){
	int nx = ++cnt;
	int mid = (l+r)>>1;
	lc[nx] = lc[x];
	rc[nx] = rc[x];
	if (l == r) {
		lh[nx] = 1;
		rh[nx] = 1;
		t[nx] = 1;
		return nx;
	}
	if (q <= mid) lc[nx] = add(lc[x], l, mid, q);
	if (q > mid) rc[nx] = add(rc[x], mid+1, r, q);

	if (lh[lc[nx]] == (mid-l+1)){
		lh[nx] = lh[lc[nx]]+lh[rc[nx]];
	} else {
		lh[nx] = lh[lc[nx]];
	}
	if (rh[rc[nx]] == (r-mid)){
		rh[nx] = rh[rc[nx]]+rh[lc[nx]];
	} else {
		rh[nx] = rh[rc[nx]];
	}
	t[nx] = max(t[lc[nx]], t[rc[nx]]);
	t[nx] = max(t[nx], rh[lc[nx]]+lh[rc[nx]]);
	return nx;
}

tiii qry(int x, int l, int r, int ql, int qr){
	if (ql > r || qr < l) return (tiii){0,0,0};
	if (ql <= l && qr >= r){
		return (tiii){t[x], lh[x], rh[x]};
	}
	int mid = (l+r)>>1;
	tiii links = qry(lc[x], l, mid, ql, qr);
	tiii rechts = qry(rc[x], mid+1, r, ql, qr);
	int ll, rr;
	if (ql <= l){
		int tmp = get<1>(links);
		if (tmp == (mid-l+1)){
			ll = tmp+get<1>(rechts);
		} else {
			ll = tmp;
		}
	} else {
		ll = 0;
	}
	if (qr >= r){
		int tmp = get<2>(rechts);
		if (tmp == (r-mid)){
			rr = tmp+get<2>(links);
		} else {
			rr = tmp;
		}
	} else {
		rr = 0;
	}
	int tt = max(get<0>(links), get<0>(rechts));
	tt = max(tt, get<2>(links)+get<1>(rechts));
	return (tiii){tt,ll,rr}; 
}

int query(int x, int l, int r){
	tuple<int,int,int> ans = qry(x,1,n,l,r);
	return max(get<0>(ans), max(get<1>(ans),get<2>(ans)));
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a+1, a+n+1);
	for (int i = n; i > 0; i--){
		root[i] = add(root[i+1], 1, n, a[i].second);
	}

	cin >> m;
	for (int i = 1; i <= m; i++){
		int L, R, W;
		cin >> L >> R >> W;
		int l = 1, r = n, ans = 0;
		while (l <= r){
			int mid = (l+r)>>1;
			if (query(root[mid],L,R)>=W){
				l = mid+1;
				ans = mid;
			} else {
				r = mid-1;
			}
		}
		cout << a[ans].first << '\n';
	}

	return 0;
}




