#include <bits/stdc++.h>
using namespace std;
int N, W;
int X[100005], Y[100005];
int endsat[400005];
vector<int> G[100005];
int belong[400005];
vector<int> GG[200005];
vector<int> surface[200005];

bool vis1[200005];
int cand;

int opp(int e){
	return (e&1) ? e+1 : e-1;
}

void dfs1(int x){
	vis1[x] = 1;
	for (int v : surface[x]){
		int vv = opp(v);
		if (Y[endsat[vv]]==Y[endsat[v]]){
			if (Y[endsat[v]] > Y[endsat[cand]]) cand = v;
		}
	}
	for (int v : GG[x]){
		if (vis1[v]) continue;
		dfs1(v);
	}
}

int d[200005];
void bfs(int start){
	queue<int> Q; Q.push(start);
	d[start] = 0;
	while (!Q.empty()){
		int x = Q.front(); Q.pop();
		for (int v : GG[x]){
			if (v != start && !d[v]) {
				d[v] = d[x]+1;
				Q.push(v);
			}
		}
	}
}

pair<int,int> diff(int e){
	int ee = endsat[opp(e)];
	e = endsat[e];
	return {X[ee]-X[e], Y[ee]-Y[e]};
}

int dir(int e){
	auto [dx, dy] = diff(e);
	if (dx > 0) return 0;
	if (dy > 0) return 1; 
	if (dx < 0) return 2; 
	return 3;      
}

int nxt(int x){
	int node = endsat[x];
	int back = dir(opp(x));
	int best = 5, who = 0;
	for (int v : G[node]){
		int cur = dir(v);
		int val = (cur-back+4)%4;
		if (val == 0) val = 4; 
		if (val < best){
			best = val;
			who = v;
		}
	}
	return who;
}

int main(){
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> X[i] >> Y[i];
	}
	cin >> W;
	for (int i = 1; i <= W; i++){
		int a, b; cin >> a >> b;
		G[a].push_back(2*i-1);
		endsat[2*i-1] = b;
		G[b].push_back(2*i);
		endsat[2*i] = a;
	}
	int cnt = 0;
	for (int i = 1; i <= 2*W; i++){
		if (!belong[i]){
			cnt++;
			// visit all along i;
			belong[i] = cnt;
			surface[cnt].push_back(i);
			int curr = nxt(i);
			while (!belong[curr]){
				belong[curr] = cnt;
				surface[cnt].push_back(curr);
				curr = nxt(curr);
			}
		}
	}
	// graph of surfaces, connected by edges.
	for (int i = 1; i <= W; i++){
		GG[belong[2*i-1]].push_back(belong[2*i]);
		GG[belong[2*i]].push_back(belong[2*i-1]);
	}
	for (int i = 1; i <= cnt; i++){
		if (!vis1[i]) {
			cand=0;
			dfs1(i);
			// cand has largest y:
			int cadd = opp(cand);
			if (X[endsat[cand]] > X[endsat[cadd]]){
				bfs(belong[cadd]);
			} else {
				bfs(belong[cand]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= W; i++){
		if (d[belong[2*i-1]]==d[belong[2*i]]) ans++;
	}
	cout << ans << '\n';
	for (int i = 1; i <= W; i++){
		if (d[belong[2*i-1]]==d[belong[2*i]]) cout << i << '\n';
	}

	return 0;
}













