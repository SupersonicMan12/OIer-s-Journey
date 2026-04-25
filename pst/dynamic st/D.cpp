// luogu P3960

#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MM = 12000005;
int n, m, q, c;
int rt[N];
// theoretical max: 300000*log(600000)/log(2)*2 < 12e6
// t means absences in interval
vector<long long> append[N];
int t[MM], lc[MM], rc[MM];
// functions needed: find kth, toggle a state, append

int kth(int &x, int l, int r, int k){
	if (!x) x = ++c;
	if (l==r) return l;
	int mid = (l+r)>>1;
	int links = (mid-l+1) - t[lc[x]];
	if (k > links) 	return kth(rc[x], mid+1, r, k-links);
	else 			return kth(lc[x], l, mid, k);
}

void toggle(int &x, int l, int r, int q){
	if (!x) x = ++c;
	if (l==r) {t[x] = 1; return;}
	int mid = (l+r)>>1;
	if (q <= mid) 	toggle(lc[x], l, mid, q);
	else 			toggle(rc[x], mid+1, r, q);
	t[x] = t[lc[x]]+t[rc[x]];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= q; i++){
		int x,y; cin >> x >> y;
		if (y == m){
			int pos = kth(rt[n+1], 1, q+n, x);
			toggle(rt[n+1], 1, q+n, pos);
			long long val = (pos>n)?append[n+1][pos-n-1]:1LL*pos*m;
			append[n+1].push_back(val);
			cout << val << '\n';
		} else {
			int pos = kth(rt[x], 1, q+m-1, y);
			toggle(rt[x], 1, q+m-1, pos);
			long long val = (pos>=m)?append[x][pos-m]:(1LL*(x-1)*m+pos);
			int poscol = kth(rt[n+1], 1, q+n, x);
			long long valcol = (poscol>n)?append[n+1][poscol-n-1]:1LL*poscol*m;
			toggle(rt[n+1], 1, q+n, poscol);
			append[x].push_back(valcol);
			append[n+1].push_back(val);
			cout << val << '\n';
		}
	}
	return 0;
}

