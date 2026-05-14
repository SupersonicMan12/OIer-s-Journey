#include <bits/stdc++.h>
using namespace std;

const int MXN = 100005;
const int MXE = 400005;

int N, W;
int X[MXN], Y[MXN];
int fr[MXE], to[MXE];

vector<int> G[MXN];

int belong[MXE], pos[MXE], go[MXE];
long long area[MXE];

vector<int> GG[MXE];
bool vis[MXE];
int d[MXE];

int opp(int e){
	return (e&1) ? e+1 : e-1;
}

int dir(int e){
	int dx = X[to[e]]-X[fr[e]];
	int dy = Y[to[e]]-Y[fr[e]];
	if (dx > 0) return 0; // right
	if (dy > 0) return 1; // up
	if (dx < 0) return 2; // left
	return 3;             // down
}

void build_next(){
	for (int i = 1; i <= N; i++){
		sort(G[i].begin(), G[i].end(), [](int a, int b){
			return dir(a) < dir(b);
		});
		for (int j = 0; j < (int)G[i].size(); j++){
			pos[G[i][j]] = j;
		}
	}

	for (int e = 1; e <= 2*W; e++){
		int u = to[e];
		const vector<int> &v = G[u];
		// finding the "upperbound"
		go[e] = v[(pos[opp(e)]+1)%v.size()];
	}
}

int find_faces(){
	int cnt = 0;
	for (int i = 1; i <= 2*W; i++){
		if (belong[i]) continue;
		++cnt;
		int cur = i;
		do {
			belong[cur] = cnt;
			int a = fr[cur], b = to[cur];
			area[cnt] += 1LL*X[a]*Y[b] - 1LL*Y[a]*X[b];
			cur = go[cur];
		} while (cur != i);
	}
	return cnt;
}

void bfs(int s){
	queue<int> Q;
	Q.push(s);
	d[s] = 0;

	while (!Q.empty()){
		int x = Q.front(); Q.pop();

		for (int v : GG[x]){
			if (d[v] == -1){
				d[v] = d[x]+1;
				Q.push(v);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> X[i] >> Y[i];
	}

	cin >> W;
	for (int i = 1; i <= W; i++){
		int a, b; cin >> a >> b;

		fr[2*i-1] = a; to[2*i-1] = b;
		fr[2*i] = b;   to[2*i] = a;

		G[a].push_back(2*i-1);
		G[b].push_back(2*i);
	}

	build_next();
	int cnt = find_faces();

	for (int i = 1; i <= W; i++){
		int a = belong[2*i-1];
		int b = belong[2*i];

		if (a == b) continue;

		GG[a].push_back(b);
		GG[b].push_back(a);
	}

	memset(d, -1, sizeof(d));

	for (int i = 1; i <= cnt; i++){
		if (vis[i]) continue;

		vector<int> comp;
		queue<int> Q;

		Q.push(i);
		vis[i] = 1;

		int start = i;

		while (!Q.empty()){
			int x = Q.front(); Q.pop();
			comp.push_back(x);

			if (area[x] > area[start]) start = x;

			for (int v : GG[x]){
				if (!vis[v]){
					vis[v] = 1;
					Q.push(v);
				}
			}
		}

		bfs(start);
	}

	vector<int> ans;

	for (int i = 1; i <= W; i++){
		int a = belong[2*i-1];
		int b = belong[2*i];

		if (d[a] == d[b]) ans.push_back(i);
	}

	cout << ans.size() << '\n';
	for (int x : ans) cout << x << '\n';

	return 0;
}