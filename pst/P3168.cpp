#include <bits/stdc++.h>
using namespace std;

int m, n, c;
int s[100005], e[100005], p[100005];
map<int,int> M;
int V[100005];
vector<int> adding[100005];
vector<int> subtracting[100005];
int root[100005];

long long t[8000005];
int lc[8000005], rc[8000005], num[8000005];

void build(int &x, int l, int r){
	if (!x) x = ++c;
	if (l == r) {
		t[x] = num[x] = 0; 
		return;
	}
	int mid = (l+r)>>1;
	build(lc[x], l, mid);
	build(rc[x], mid+1, r);
}

int add(int x, int l, int r, int q, int v){
	if (l == r){
		t[++c] = t[x]+1LL*v*q;
		num[c] = num[x]+v;
		return c;
	}
	int mid = (l+r)>>1;
	int nx = ++c;
	if (M[q] <= mid){
		lc[nx] = add(lc[x], l, mid, q, v);
		rc[nx] = rc[x];
	} else {
		lc[nx] = lc[x];
		rc[nx] = add(rc[x], mid+1, r, q, v);
	}
	t[nx] = t[lc[nx]]+t[rc[nx]];
	num[nx] = num[lc[nx]]+num[rc[nx]];
	return nx;
}

long long find(int x, int l, int r, int k){
	if (l == r){
		return 1LL*min(k, num[x])*V[l];
	}
	int mid = (l + r) >> 1;
	if (k <= num[lc[x]]){
		return find(lc[x], l, mid, k);
	} else {
		return t[lc[x]] + find(rc[x], mid+1, r, k-num[lc[x]]);
	}
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	set<int> S;
	for (int i = 1; i <= m; i++){
		cin >> s[i] >> e[i] >> p[i];
		adding[s[i]].push_back(p[i]);
		subtracting[e[i]+1].push_back(p[i]);
		S.insert(p[i]);
	}
	int cnt = 0;
	for (int v: S) {
		M[v] = ++cnt;
		V[cnt] = v;
	}
	build(root[0], 1, cnt);
	for (int i = 1; i <= n; i++){
		root[i] = root[i-1];
		for (int a: adding[i]){
			root[i] = add(root[i], 1, cnt, a, 1);
		}
		for (int ss: subtracting[i]){
			root[i] = add(root[i], 1, cnt, ss, -1);
		}
	}
	long long pre = 1;
	for (int i = 1; i <= n; i++){
		int x, a, b, cc; cin >> x >> a >> b >> cc;
		pre %= cc;
		int k = 1+(1LL*a*pre+b)%cc;
		pre = find(root[x], 1, cnt, k);
		cout << pre << '\n';
	}

	return 0;
}