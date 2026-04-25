#include <bits/stdc++.h>
using namespace std;

int n, c;
char t[4000005];
int lc[4000005], rc[4000005];
int where[100005];
int root[100005];

void build(int &x, int l, int r){
	if (!x) x = ++c;
	if (l==r){
		t[x] = ' ';
		return;
	}
	int mid = (l+r)>>1;
	build(lc[x], l, mid);
	build(rc[x], mid+1, r);
}

int update(int x, int l, int r, int q, char v){
	if (l == r){
		t[++c] = v;
		return c;
	}
	int mid = (l+r)>>1;
	int nx = ++c;
	if (q <= mid){
		lc[nx] = update(lc[x], l, mid, q, v);
		rc[nx] = rc[x];
	} else {
		lc[nx] = lc[x];
		rc[nx] = update(rc[x], mid+1, r, q, v);
	}
	return nx;
}

char qry(int x, int l, int r, int q){
	if (l == r) return t[x];
	int mid = (l+r)>>1;
	if (q<=mid) return qry(lc[x], l, mid, q);
	else return qry(rc[x], mid+1, r, q);
}

int main(){
	cin >> n;
	build(root[0], 1, n);
	where[0] = 1;
	int curr = 1;
	for (int i = 1; i <= n; i++){
		char op; cin >> op;
		if (op == 'T'){
			char ch; cin >> ch;
			root[curr] = update(root[curr-1], 1, n, where[curr-1], ch);
			where[curr] = where[curr-1]+1;
			curr++;
		}
		if (op == 'Q'){
			int x; cin >> x;
			cout << qry(root[curr-1], 1, n, x) << '\n';
		} 
		if (op == 'U'){
			int x; cin >> x;
			root[curr] = root[curr-x-1];
			where[curr] = where[curr-x-1];
			curr++;
		}
	}
	return 0;
}


