#include <bits/stdc++.h>
using namespace std;

int n,m;
int d[2000005];
pair<int,int> P[2000005];
int to[2000005];
vector<int> V;
bool vis[2000005];

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> d[i*2-1] >> d[i*2];
		P[i*2-1] = {d[i*2-1], i*2-1};
		P[i*2] = {d[i*2],i*2};
	}
	P[2*n+1] = {2000001,2*n+1};
	int N = 2*n;
	sort(P+1, P+N+2);
	for (int i = 1; i <= n; i++){
		to[i*2-1] = lower_bound(P+1, P+N+2, make_pair(d[2*i]+1, 0))->second;
		to[i*2] = lower_bound(P+1, P+N+2, make_pair(d[2*i-1]+1, 0))->second;
	}
	int curr = P[1].second, ans = 0;
	while (to[curr]){
		// cout << curr;
		vis[curr] = 1;
		curr = to[curr];
		ans++;
	}
	// cout << ans << '\n';
	for (int i = 1; i <= N; i++){
		if (!vis[i]){
			int tmp = 0;
			curr = i;
			while (!vis[curr]){
				// cout << curr << '\n';
				vis[curr] = 1;
				curr = to[curr];
				tmp++;
			}
			V.push_back(tmp);
			// cout << tmp << '\n';
		}
	}
	sort(V.begin(), V.end(), greater<int>());
	int cc = V.size();
	for (int i = 0; i < cc; i++){
		ans += (V[i]+2);
		m--;
		if (m == 0) break;
	}
	int couples = m/2;
	ans += 4*couples;
	if (m % 2) ans += 1;
	cout << ans << endl;
}



