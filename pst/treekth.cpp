#include <bits/stdc++.h>
using namespace std;

int n, m, wmax;
int w[100005];
int root[100005];
vector<int> G[100005];
int up[100005][20], c, dep[100005];

int t[2000005], lc[2000005], rc[2000005];
int add(int x, int l, int r, int q){
	int nx = ++c;
	int mid = (l+r)>>1;
	lc[nx] = lc[x];
	rc[nx] = rc[x];
	t[nx] = t[x] + 1;
	if (l == r) return nx;
	if (q <= mid) lc[nx] = add(lc[x], l, mid, q);
	else 		  rc[nx] = add(rc[x], mid+1, r, q);
	return nx;
}

void dfs(int x, int f){
	up[x][0] = f;
	dep[x] = dep[f]+1;
	for (int i = 1; i <= 17; i++){
		up[x][i] = up[up[x][i-1]][i-1];
	}
	for (int v : G[x]){
		if (v == f) continue;
		root[v] = add(root[x], 1, wmax, w[v]);
		dfs(v, x);
	}
}

int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 17; i >= 0; i--){
		if (dep[x]-(1<<i) >= dep[y]){
			x = up[x][i];
		}
	}
	if (x == y) return x;
	for (int i = 17; i >= 0; i--){
		if (up[x][i]!=up[y][i]){
			x = up[x][i];
			y = up[y][i];
		}
	}
	return up[x][0];
}

int qry(int p1, int p2, int n1, int n2, int l, int r, int k){
	if (l == r) return l;
	int mid = (l+r)>>1;
	int lhs = t[lc[p1]]+t[lc[p2]]-t[lc[n1]]-t[lc[n2]];
	if (k <= lhs) return qry(lc[p1], lc[p2], lc[n1], lc[n2], l, mid, k);
	else return qry(rc[p1], rc[p2], rc[n1], rc[n2], mid+1, r, k-lhs);
}


int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> w[i];
		wmax = max(wmax, w[i]);
	}
	for (int i = 1; i < n; i++){
		int x, y; cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	root[1] = add(root[1], 1, wmax, w[1]);
	dfs(1, 0);
	for (int i = 1; i <= m; i++){
		int a, b, k; cin >> a >> b >> k;
		int lcaa = lca(a, b);
		cout << qry(root[a],root[b],root[lcaa],root[up[lcaa][0]],1,wmax,k) << '\n';
	}

	return 0;
}

