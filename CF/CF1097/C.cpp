#include <bits/stdc++.h>
using namespace std;

const long long CAP = 1000000000000000001LL;
int n, q;
vector<pair<int,int>> G[500005];
int d[500005], pa[500005];
long long Q[1000006];
int ans[1000006];
vector<int> passon;

void dfs(int x, long long M, long long time){
	if (d[x]==0) {
		for (int v : passon){
			ans[v] = x;
		}
		return;
	}
	// at this point, all the Q are identical!!
	if (M >= CAP){
		auto nxt = G[x][(Q[passon[0]]%d[x]+time%d[x])%d[x]];
		dfs(nxt.first, M, time+nxt.second);
		return;
	}
	if (M%d[x]==0){
		auto nxt = G[x][(Q[passon[0]]+time)%d[x]];
		dfs(nxt.first, M, time+nxt.second);
	} else {
		__int128 tt = (__int128)M/gcd(M,d[x])*d[x];
		long long Mp;
		if (tt >= CAP) Mp = CAP;
		else Mp = (long long)tt;
		// very importantly, when Mp = CAP, Mp loses meaning!!
		map<long long, vector<int>> splitt;
		for (int qt: passon){
			long long q = Q[qt];
			if (Mp < CAP) splitt[(q+time)%Mp].push_back(qt);
			else splitt[q].push_back(qt);
		}
		for (auto [u, v]: splitt){
			passon.clear();
			for (int k : v) passon.push_back(k);
			int c;
			if (Mp < CAP) c = u%d[x];
			else c = (u%d[x]+time%d[x])%d[x];
			auto nxt = G[x][c];
			dfs(nxt.first, Mp, time+nxt.second);
		}
	}
}

void solve(){
	passon.clear();
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		G[i].clear(); d[i] = 0;
	}
	for (int i = 2; i <= n; i++){
		cin >> pa[i];
	}
	for (int i = 2; i <= n; i++){
		int l; cin >> l;
		d[pa[i]]++;
		G[pa[i]].push_back({i,l});
	}
	for (int i = 1; i <= q; i++){
		cin >> Q[i];
		passon.push_back(i);
	}
	dfs(1, 1, 0);
	for (int i = 1; i <= q; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while (T--){
		solve();
	}
	return 0;
}
