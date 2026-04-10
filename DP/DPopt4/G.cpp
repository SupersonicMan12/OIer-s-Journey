#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
int M, N, m, n;
pair<int,int> low[500005], high[500005];
pair<int,int> lo[500005], hi[500005];
int u[500005];
long long ans = 0;

long long area(int i, int j){
	if (lo[i].first >= hi[j].first && lo[i].second >= hi[j].second) return -(1LL<<60);
	return 1LL * (hi[j].first - lo[i].first) * (hi[j].second - lo[i].second);
}

void solve(int l, int r){
	// cout << l << r << '\n';
	int mid = (l+r)>>1;
	long long best = -(1LL<<60);
	int theone = 0;
	for (int i = u[l-1]; i <= u[r+1]; i++){
		long long A = area(mid, i);
		if (best < A){
			best = A;
			theone = i;
		}
	}
	ans = max(ans, best);
	u[mid] = theone;
	if (l == r) return;
	if (l < mid) solve(l, mid-1);
	solve(mid+1, r);
}


int main(){
	cin >> M >> N;
	for (int i = 1; i <= M; i++){
		cin >> low[i].first >> low[i].second;
	}
	sort(low+1, low+M+1);
	lo[0].second = INF;
	for (int i = 1; i <= M; i++){
		if (lo[m].second <= low[i].second) continue;
		lo[++m] = low[i];
	}
	for (int i = 1; i <= N; i++){
		cin >> high[i].first >> high[i].second;
	}
	sort(high+1, high+N+1);
	for (int i = 1; i <= N; i++){
		while (n && hi[n].second <= high[i].second) n--;
		hi[++n] = high[i];
	}
	u[0] = 1, u[m+1] = n;
	solve(1, m);
	cout << ans << '\n';

	return 0;
}