#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000009;
int n, m;
struct worker{
	int s, e;
	bool operator<(const worker &other) const{
		if (s != other.s) return s < other.s;
		return e > other.e;
	}
} w[200005], W[200005];
int sta[200005];
int nxt[200005][19];

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> w[i].s >> w[i].e;
		if (w[i].s>w[i].e) w[i].e += m;
	}
	sort(w+1, w+n+1);
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (cnt == 0 || (W[cnt].e<w[i].e)){
			W[++cnt] = w[i];
			sta[cnt] = w[i].s;
		}
	}
	// W[1..cnt] represent the final candidates
	int ans = INF;
	W[0].e = INF;
	for (int i = 1; i <= cnt; i++){
		int curr = i;
		int leftmost = W[curr].s;
		vector<int> V; V.push_back(curr);
		int tans = 1;
		while (W[curr].e < leftmost+m){
			if (nxt[curr][0]){
				// finish directly with O(17)
				for (int i = 18; i >= 0; i--){
					if (W[nxt[curr][i]].e < leftmost+m){
						curr = nxt[curr][i];
						tans += (1<<i);
					}
				}
				tans++;
				curr = nxt[curr][0];
				if (!(curr && W[curr].e >= leftmost+m)) tans = INF;
				break;
			}
			int tem = curr;
			curr = upper_bound(sta+1,sta+cnt+1,W[curr].e)-sta-1;
			if (curr == tem) curr = 0;
			if (!nxt[curr][0]&&curr!=0) {
				V.push_back(curr);
				nxt[tem][0] = curr;
			}
			if (curr == 0) { // dead.
				tans = INF; break;
			}
			tans++;
		}
		for (int i = 1; i <= 18; i++){
			for (int v : V){
				nxt[v][i] = nxt[nxt[v][i-1]][i-1];
			}
		}
		ans = min(ans, tans);
	}
	if (ans == INF) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}