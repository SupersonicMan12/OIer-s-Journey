#include <bits/stdc++.h>
using namespace std;

long long INF = 0x3f3f3f3f3f3f3f3f;
long long dp[66000][16];

void mx(long long &x, long long y){
	if (y < x) x = y;
}

int diff[400005];
int fa[400005], x[400005];
vector<tuple<int,int,int>> krusk;

int find(int x){
	if (fa[x]==x) return x;
	return fa[x] = find(fa[x]);
}

void Union(int x, int y){
	if (fa[x] != fa[y]){
		x = find(x);
		y = find(y);
		fa[x] = y;
	}
}


bool detect_zero(vector<int> s, vector<int> t, int n){
	// discretize
	s.push_back(1000000000); t.push_back(1);
	set<int> S; map<int,int> M;
	for (auto ss: s) S.insert(ss);
	for (auto tt: t) S.insert(tt);
	int cnt = 0;
	for (auto ss: S) M[ss] = ++cnt;
	for (auto &ss: s) ss = M[ss];
	for (auto &tt: t) tt = M[tt];
	// chafen:
	
	for (int i = 1; i <= cnt; i++) fa[i] = i;
	for (int i = 0; i <= n; i++){
		diff[s[i]]++; 
		diff[t[i]]--;
		Union(s[i], t[i]);
	}
	int curr = 0;
	for (int i = 1; i < cnt; i++){
		// cout << diff[i] << endl;
		curr += diff[i];
		if (curr < 0){
			Union(i, i+1);
		}
		if (curr > 0) return 0;
	}
	int xx = find(1);
	bool flag = 1;
	for (int i = 2; i <= cnt; i++){
		if (find(i)!=xx) flag = 0;
	}
	if (flag) return 1;
	else return 0;
}

long long solve(vector<int> s, vector<int> t, int n){
	// discretize
	s.push_back(1000000000); t.push_back(1);
	set<int> S; map<int,int> M;
	for (auto ss: s) S.insert(ss);
	for (auto tt: t) S.insert(tt);
	int cnt = 0;
	for (auto ss: S) {
		M[ss] = ++cnt;
		x[cnt] = ss;
	}
	for (auto &ss: s) ss = M[ss];
	for (auto &tt: t) tt = M[tt];
	// chafen:
	
	for (int i = 1; i <= cnt; i++) fa[i] = i;
	for (int i = 0; i <= n; i++){
		diff[s[i]]++; 
		diff[t[i]]--;
		Union(s[i], t[i]);
	}
	int curr = 0;
	long long ans = 0;
	for (int i = 1; i < cnt; i++){
		// cout << diff[i] << endl;
		curr += diff[i];
		if (curr < 0){
			Union(i, i+1);
		} else if (curr > 0) {
			Union(i, i+1);
			ans += 1LL*curr*(x[i+1]-x[i]);
		} else {
			krusk.push_back({x[i+1]-x[i], i, i+1});
		}
	}
	sort(krusk.begin(), krusk.end());
	for (auto [u,v,w]: krusk){
		if (find(v)==find(w)) continue;
		Union(v, w);
		ans += u;
	}
	return ans;
}

long long plan_roller_coaster(vector<int> s, vector<int> t){
	int n = s.size();
	return solve(s,t,n);
	if (n <= 16){
		// bitmask DP
		memset(dp, 0x3f, sizeof(dp));
		int N = (1<<n)-1;
		for (int i = 0; i < n; i++) dp[1<<i][i] = 0;
		for (int M = 0; M < N; M++){
			for (int curr = 0; curr < n; curr++){
				if (dp[M][curr] == INF) continue;
				for (int nxt = 0; nxt < n; nxt++){
					if ((M>>nxt)&1) continue;
					mx(dp[M^(1<<nxt)][nxt], dp[M][curr]+max(t[curr]-s[nxt],0));
				}
			}
		}
		long long ans = INF;
		for (int i = 0; i < n; i++){
			if (dp[N][i]<ans)ans=dp[N][i];
		}
		return ans;
	} 
}

