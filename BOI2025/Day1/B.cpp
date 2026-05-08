#include <bits/stdc++.h>
using namespace std;

int n, m, t, N, ecnt;
int c[1000005];
int head[41000005];
int to[41000005];
int nxt[41000005];
bool vis[41000005];
int seq[41000005];
bool inseq[41000005];
int cnt, fcnt, stop;
vector<int> touched, used;

void clear(){
	for (int i : used){
		vis[i] = inseq[i] = 0;
	}
	for (int i: touched){
		head[i] = 0;
	}
	touched.clear();
	used.clear();
	ecnt = cnt = 0;
}

inline void add_edge(int u, int v){
    //G[u].push_back(v);
    if (head[u]==0) touched.push_back(u);
    to[++ecnt] = v;
    nxt[ecnt] = head[u];
    head[u] = ecnt;
}

void add(int a, int i, int b){
	for (int bit = 0; bit < 20; bit++){
		int froma = m+40*(a-1)+((((c[i]>>bit)&1)^1)*20)+bit+1;
		int tob = m+40*(b-1)+(((c[i]>>bit)&1)*20)+bit+1;
		add_edge(froma, i);
		add_edge(i, tob);
	}
}

bool dfs(int x){
	vis[x] = 1;
	used.push_back(x);
	seq[++cnt] = x; inseq[x]=1;
	for(int k = head[x]; k ;k = nxt[k]){
		int v = to[k];
		if (inseq[v]) {
			stop = v;
			return 1;
		}
		if (vis[v]) continue;
		if (dfs(v)) return 1;
	}
	cnt--; inseq[x]=0;
	return 0;
}

void solve(){
	cin >> n >> m;
	N = m+40*n;
	for (int i = 1; i <= m; i++){
		int a, b; cin >> a >> b >> c[i];
		// id(a,i,*) -> i -> id(b,i,*)
		add(a,i,b);
	}
	bool flag = 1;
	for (int i = 1; i <= N; i++){
		if (!vis[i]) {
			if (dfs(i)){
				vector<int> ans;
				fcnt = 0;
				for (int i = cnt; i >= 1; i--){
					int x = seq[i];
					if (x <= m){
						ans.push_back(x);
						fcnt++;
					}
					if (x == stop) break;
				}
				cout << "YES\n";
				cout << fcnt << ' ';
				for (int i = fcnt-1; i >= 0; i--){
					cout << ans[i] << ' ';
				}
				cout << "\n";
				flag = 0;
				break;
			}
		}
	}
	if (flag) cout << "NO\n";
	clear();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--){
		solve();
	}
	return 0;
}