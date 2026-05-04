#include <bits/stdc++.h>
using namespace std;

long long l, r, p;

const int primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
const int MAXX = 2944733;
int STOP;
int number[MAXX], cnt;
unordered_map<int, int> id;
struct special{
	vector<pair<int,int>> V;
	void add(int m, int k){
		int w = 0;
		for (auto [om, ok]: V){
			if (om<=m&&ok<=k){
				return;
			}
		}
		for (auto [om, ok]: V){
			if (!(m<=om&&k<=ok)){
				V[w++] = {om, ok};
			}
		}
		V.resize(w);
		V.push_back({m,k});
	}
} state[MAXX];

void dfs(int i, long long x){
	if (i == STOP) {
		number[++cnt] = x;
		return;
	}
	while (x <= r){
		dfs(i+1, x);
		x = x*primes[i];
	}
}

void prec(){
	STOP = upper_bound(primes, primes+25, p-1)-primes;
	dfs(0, 1);
	sort(number+1, number+cnt+1);
	id.max_load_factor(0.7);
	id.reserve(cnt + 5);
	for (int i = 1; i <= cnt; i++) id[number[i]] = i;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> l >> r >> p;
	prec();
	for (int i = 1; i <= cnt; i++) state[i].V.clear();
	int stop = upper_bound(number+1, number+cnt+1, r)-number-1;
	state[1].V.push_back({0,0});
	int ans = 0;
	for (int i = 1; i <= stop; i++){
		if (state[i].V.empty()) continue;
		if (number[i] >= l) ans++;
		for (auto [m,k]: state[i].V){
			int lim = p-k-1;
			for (int d = max(m,2); d <= lim; d++){
				if (1LL*number[i]*d > 1LL*r) break;
				state[id[number[i]*d]].add(d, k+1);
			}
		}
	}
	cout << ans << endl;

	return 0;
}


