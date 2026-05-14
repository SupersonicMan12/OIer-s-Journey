#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int h; long long w,n;
map<int,vector<long long>>M;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w >> n;
	for (int i = 1; i <= n; i++){
		int a; long long b; cin >> a >> b;
		M[a].push_back(b);
	}
	int cnt = 0;
	long long ans = 0;
	vector<long long> VV; 
	long long curr = 0;
	for (auto &[u,V]: M){
		int l = V.size();
		sort(V.begin(), V.end());
		long long small = INF, big = 0;
		for (long long v : V){
			small = min(small, v);
			big = max(big, v);
		}
		long long large = 0;
		for (int i = 0; i < l-1; i++){
			large = max(large, V[i+1]-V[i]);
		}
		large = max(large, V[0]-1);
		large = max(large, w-V[l-1]);
		ans += 2LL*(big-1);
		long long opt = 2LL*(w-1)-2LL*large;
		VV.push_back(opt);
		curr += opt;
		cnt++;
	}

	sort(VV.begin(), VV.end(), greater<long long>());
	// mandatory pair:
	if (cnt >= 2){
		curr += (2LL*(w-1)-VV[0]-VV[1]);
		ans = min(ans, curr);
		for (int i = 2; i < cnt-1; i += 2){
			curr += (2LL*(w-1)-VV[i]-VV[i+1]);
			ans = min(ans, curr);
		}
	}
	
	cout << ans << '\n';

	return 0;
}






