#include <bits/stdc++.h>
using namespace std;

string s[20005];
map<char,int> t[2000005];
int sz[2000005];
int mn2[2000005];
int mn1[2000005];

struct ansbody{
	int l, x, y;
	bool operator<(const ansbody &other) const{
		if (l != other.l) return l < other.l;
		if (x != other.x) return x > other.x;
		return y > other.y;
	}
} ans;

void add(int x, int v){
	if (v < mn1[x]){
		mn2[x] = mn1[x];
		mn1[x] = v;
	} else if (v < mn2[x]){
		mn2[x] = v;
	}
}

void dfs(int x, int dep){
	for (auto [_, v] : t[x]){
		dfs(v, dep+1);
		sz[x] += sz[v];
		add(x, mn1[v]);
		add(x, mn2[v]);
	}
	if (sz[x] > 1){
		ans = max(ans, ansbody{dep, mn1[x], mn2[x]});
	}
}

int main(){
	memset(mn2, 0x3f, sizeof(mn2));
	memset(mn1, 0x3f, sizeof(mn1));
	int n; cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		int p = 0;
		for (char c : s[i]){
			if (!t[p].count(c)) 
				t[p][c] = ++cnt;
			p = t[p][c];
		}
		mn1[p] = i;
		sz[p]++;
	}
	ans = (ansbody){0, 10000000, 10000000};
	dfs(0, 0);
	cout << s[ans.x] << '\n' << s[ans.y] << '\n';
	return 0;
}
