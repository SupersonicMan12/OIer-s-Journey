#include <bits/stdc++.h>
using namespace std;

int n, m, c; // 1e5
int a[100005];
int o[200005], ccc;
bool op[100005];
int ll[100005], rr[100005], kk[100005];
int qq[100005], xx[100005];
int t[8000005];
int lc[8000005], rc[8000005];
int root[100005];
map<int,int> M; 

void build(int &x, int l, int r){
	if (!x) x = ++c;
	if (l==r) return;
	int mid = (l+r)>>1;
	build(lc[x], l, mid);
	build(rc[x], mid+1, r);
}

int add(int x, int l, int r, int q, int v){
	int nx = ++c;
	t[nx] = t[x] + v;
	lc[nx] = lc[x];
	rc[nx] = rc[x];
	if (l == r) return nx;
	int mid = (l+r)>>1;
	if (q <= mid) lc[nx] = add(lc[x], l, mid, q, v);
	else rc[nx] = add(rc[x], mid+1, r, q, v);
	return nx;
}

int query(const vector<int> &x, const vector<int> &y, int l, int r, int k){
	if (l == r) return l;
	int mid = (l+r)>>1;
	int sx = 0, sy = 0;
	for (int v: x) sx += t[lc[v]];
	for (int v: y) sy += t[lc[v]];
	if (sy - sx >= k){
		vector<int> xx, yy; 
		for (int v : x) xx.push_back(lc[v]);
		for (int v : y) yy.push_back(lc[v]);
		return query(xx, yy, l, mid, k);
	} else {
		vector<int> xx, yy;
		for (int v : x) xx.push_back(rc[v]);
		for (int v : y) yy.push_back(rc[v]);
		return query(xx, yy, mid+1, r, k-sy+sx);
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		o[++ccc] = a[i];
	}
	// fenwick build
	for (int i = 1; i <= m; i++){
		char ch; cin >> ch;
		op[i] = (ch=='Q');
		if (op[i]){
			cin >> ll[i] >> rr[i] >> kk[i];
		} else {
			cin >> qq[i] >> xx[i];	
			o[++ccc] = xx[i];
		}
	}
	sort(o+1, o+1+ccc);
	ccc = unique(o+1, o+1+ccc)-o-1;
	for (int i = 1; i <= ccc; i++){
		M[o[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
    	int v = M[a[i]];
    	for (int j = i; j <= n; j += j & -j) {
        	root[j] = add(root[j], 1, ccc, v, 1);
	    }
	}
	for (int i = 1; i <= m; i++){
		if (op[i]){
			vector<int> X;
			for (int j = ll[i]-1; j > 0; j -= (j&(-j))){
				X.push_back(root[j]);
			}
			vector<int> Y;
			for (int j = rr[i]; j > 0; j -= (j&(-j))){
				Y.push_back(root[j]);
			}
			cout << o[query(X, Y, 1, ccc, kk[i])] << '\n';
		} else {
			int x = qq[i];
			for (int j = x; j <= n; j+= (j&(-j))){
				root[j] = add(root[j], 1, ccc, M[a[x]], -1);
				root[j] = add(root[j], 1, ccc, M[xx[i]], 1);
			}
			a[x] = xx[i];
		}
	}

	return 0;
}