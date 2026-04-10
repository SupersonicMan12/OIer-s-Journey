#include <bits/stdc++.h>
using namespace std;

int n;
bitset<24> adj[25];
bitset<24> dp[17000000];
bitset<24> ans[25];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			char c; cin >> c;
			adj[i][j] = (c=='1');
		}
	}
	int L = (1<<n)-1;
	// O(n2^n)
	dp[1] = 1;
	for (int i = 1; i < L; i++){
		for (int j = 0; j < n; j++){
			if (i & (1<<j)) continue;
			if ((dp[i] & adj[j]).any()) {
				dp[i|(1<<j)].set(j);
			}
		}
	}

	for (int S = 1; S <= L; S++){
		if (!(S & 1)) continue;
		int T = (L^S)|1;
		for (int i = 0; i < n; i++){
			if (dp[S][i]){
				ans[i] |= dp[T];
			} 
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << ans[i][j];
		}
		cout << '\n';
	}

	return 0;
}



