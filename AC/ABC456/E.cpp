#include <bits/stdc++.h>
using namespace std;

int t;

int n,m,w;
vector<int> G[100005];
vector<int> GG[1000005];
// node*w+day
int can[100005][11];
int cnt[1000005];

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a,b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) G[i].push_back(i);
	cin >> w;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= w; j++){
			char c; cin >> c;
			can[i][j] = (c=='o');
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= w; j++){
			if (!can[i][j]) continue;
			int prenode = (i-1)*w+(j);
			for (int v : G[i]){
				if (!can[v][((j+1)>w)?1:(j+1)]) continue;
				int nxtnode = (v-1)*w+(j%w+1);
				GG[prenode].push_back(nxtnode);
				cnt[nxtnode]++;
			}
		}
	}
	int N = n*w;
	queue<int> Q;
	for (int i = 1; i <= N; i++){
		if (cnt[i]==0) Q.push(i);
	}
	int cc = 0;
	while (!Q.empty()){
		int x = Q.front(); Q.pop();
		cc++;
		for (int v : GG[x]){
			cnt[v]--;
			if (cnt[v]==0){
				Q.push(v);
			}
		}
	}
	if (cc == N){
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
	for (int i = 1; i <= n; i++) G[i].clear();
	for (int i = 1; i <= N; i++) GG[i].clear();
	for (int i = 1; i <= N; i++) cnt[i]=0;

	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) solve();
	return 0;
}