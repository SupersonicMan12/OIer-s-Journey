#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n;
int x, y;
map<int,int> X;
map<int,int> Y;
int v, e;

vector<int> G[400005];
bool vis[400005];

void dfs(int x){
	vis[x] = 1;
	v++;
	for (int v : G[x]){
		e++;
		if (vis[v]) continue;
		dfs(v);
	}
}


int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> n;
	x = 0, y = n;
	for (int i = 1; i <= n; i++){
		int a, b; cin >> a >> b;
		if (!X.count(a)){
			X[a] = ++x;
		}
		if (!Y.count(b)){
			Y[b] = ++y;
		}
		G[X[a]].push_back(Y[b]);
		G[Y[b]].push_back(X[a]);
	}
	long long ans = 1;
	for (int i = 1; i <= x; i++){
		if (vis[i]) continue;
		v = 0, e = 0;
		dfs(i);
		e/=2;
		if (e > v) ans = 0;
		else if (e == v) ans = (ans * 2) %MOD;
		else if (e == v-1) ans = (ans * v)%MOD;
	}
	for (int i = n+1; i <= y; i++){
		if (vis[i]) continue;
		v = 0, e = 0;
		dfs(i);
		e/=2;
		if (e > v) ans = 0;
		else if (e == v) ans = (ans * 2) %MOD;
		else if (e == v-1) ans = (ans * v)%MOD;
	}

	cout << ans << endl;

	return 0;
}