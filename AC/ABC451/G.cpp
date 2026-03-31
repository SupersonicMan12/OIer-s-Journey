#include <bits/stdc++.h>
using namespace std;

int t, n, m, k;
vector<pair<int,int>> T[200005];
struct Nontree{
	int u,v,w;
} nontree[200005];
int fa[200005];
int A[200005];
int bas[31];
int nxt[6000005][2], sz[6000005];

int find(int x){
	if (fa[x]==x) return x;
	else return fa[x] = find(fa[x]);
}

void dfs(int x, int ff){
	for (auto [v,w] : T[x]){
		if (v == ff) continue;
		A[v] = A[x]^w;
		dfs(v, x);
	}
}

int f(int x){
    for (int j = 29; j >= 0; j--)
        if ((x >> j) & 1 && bas[j])
            x ^= bas[j];
    return x;
}

void solve(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) fa[i] = i;
	int cnt = 0;
	for (int i = 1; i <= m; i++){
		int u,v,w; cin >> u >> v >> w;
		if (find(u)==find(v)) 
			nontree[++cnt] = {u,v,w};
		else {
			T[u].push_back({v, w});
			T[v].push_back({u, w});
			fa[find(u)] = find(v);
		}
	}
	dfs(1, 1);
	memset(bas, 0, sizeof(bas));
	for (int i = 1; i <= cnt; i++){
		int x = A[nontree[i].u]^A[nontree[i].v]^nontree[i].w;
		for (int j = 29; j >= 0; j--){
			if (!((x>>j)&1)) continue;
			if (!bas[j]) {bas[j] = x; break;}
			x ^= bas[j];
		}
	}
	int c = 0;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
	    int B = f(A[i]);
	    int curr = 0;
	    for (int bit = (1<<29); bit > 0; bit >>= 1){
	        int b = (B & bit) ? 1 : 0;
	        if (k & bit){
	            ans += sz[nxt[curr][b]];
	            curr = nxt[curr][b ^ 1];
	            if (!curr) break;
	        } else {
	            curr = nxt[curr][b];
	            if (!curr) break;
	        }
	    }
	    ans += sz[curr];

	    // insert after query
	    curr = 0;
	    for (int bit = (1<<29); bit > 0; bit >>= 1){
	        int b = (B & bit) ? 1 : 0;
	        if (!nxt[curr][b]) nxt[curr][b] = ++c;
	        curr = nxt[curr][b];
	        sz[curr]++;
	    }
	}
		cout << ans << '\n';
	for (int i = 1; i <= n; i++){
		T[i].clear();
	}
	for (int i = 0; i <= c; i++){
		nxt[i][0]=nxt[i][1]=0; sz[i]=0;
	}
}

int main(){
	cin >> t; while (t--) solve();
	return 0;
}






