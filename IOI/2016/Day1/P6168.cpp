#include <bits/stdc++.h>
using namespace std;

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

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<int> s, t;
	for (int i = 1; i <= n; i++){
		int x, y; cin >> x >> y;
		s.push_back(x); 
		t.push_back(y);
	}
	cout << solve(s, t, n) << endl;
	return 0;
}






