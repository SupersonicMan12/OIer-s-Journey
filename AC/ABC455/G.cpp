#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;
int n,k,B;
ull w[N], p[N];
int L[N], freq[N];
vector<int> val[N];
int buck[N], h[N], S[N];

void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		val[a[i]].push_back(i);
	}
	while (k--){
		memset(buck, 0, sizeof(buck));
		map<int,vector<int>> bucket;
		cin >> B;
		for (int i = 1; i <= n; i++){
			ull s = 0;
			for (int j = 0; j < val[i].size();j++){
				w[val[i][j]] = rng();
				if (j < B-1) s += w[val[i][j]];
				if (j % B == B-1) w[val[i][j]] = -s;
			}
			h[val[i]] = rng();
		}
		bucket[0].push_back(0);
		for (int i = 1; i <= n; i++){
			p[i] = p[i-1]+w[i];
			bucket[p[i]].push_back(i);
		}
		int over = 0, Lt = 1;
		for (int i = 1; i <= n; i++){
			freq[a[i]]++;
			if (freq[a[i]] > B) over++;
			while (over > 1){
				freq[Lt]--;
				if (freq[Lt] <= B) over--;
				Lt++;
			}
			L[i] = Lt;
		}
		long long ans1 = 0;
		for (int i = 0; i <= n; i++){
			vector<int> V;
			for (int v : val[i]){
				int lo = lower_bound(V.begin(), V.end(), v)-V.begin();
				ans1 += val[i].size()-lo;
				V.push_back(v);
			}
		}
		// ans1 completed
		int l = 1, distinct = 0;
		ull H = 0;
		for (int r = 1; r <= n; r++){
			buck[a[r]]++;
			if (buck[a[r]]==1){
				distinct++;
			}
			if (distinct > B){
				while (1){
					buck[a[l]]--;
					H -= ()
					if (buck[a[l]]==0){
						break;
					}
				}
			}
			// UNFINISHED
		}
	}
}

int main(){
	int T; cin >> T;
	while (T--){
		solve();
	}
	return 0;
}