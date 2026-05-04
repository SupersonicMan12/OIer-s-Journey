#include <bits/stdc++.h>
using namespace std;

long long l, r, p;

const int primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
const int MAXX = 2944733;
int number[MAXX], cnt;
unordered_map<int, int> id;
vector<pair<int,int>> state[MAXX];

void dfs(int i, long long x){
	if (i == 25) {
		number[++cnt] = x;
		return;
	}
	while (x <= r){
		dfs(i+1, x);
		x = x*primes[i];
	}
}

void prec(){
	dfs(0, 1);
	sort(number+1, number+cnt+1);
	for (int i = 1; i <= cnt; i++) id[number[i]] = i;
}

int solve(int cap){
	if (cap == 0) return 0;
	for (int i = 1; i <= cnt; i++) state[i].clear();
	int stop = upper_bound(number+1, number+cnt+1, cap)-number-1;
	state[1].push_back({0,0});
	int ans = 0;
	for (int i = 1; i <= stop; i++){
		if (state[i].empty()) continue;
		ans++;
		for (auto [m,k]: state[i]){
			int lim = p-k-1;
			for (int d = max(2,m); d <= lim; d++){
				if (1LL*number[i]*d > 1LL*cap) break;
				state[id[number[i]*d]].push_back({d, k+1});
			}
		}
	}
	return ans;
}

int main(){
	cin >> l >> r >> p;
	prec();
	cout << solve(r)-solve(l-1) << '\n';

	return 0;
}


