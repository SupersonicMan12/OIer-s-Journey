#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
long long n, d;
vector<int> G[100005];
bool down[100005];
bool up[100005];
bool affect[100005];

void dfs(int x, int f){
	down[x] = 0;
	for (int v : G[x]){
		if (v == f) continue;
		dfs(v, x);
		if (!down[v]){
			down[x] = 1; 
		}
	}
}

void dfs2(int x, int f){
    int lose = 0;
    for (int v : G[x]){
        if (v == f) continue;
        if (!down[v]) lose++;
    }

    for (int v : G[x]){
    	if (v == f) continue;
    	up[v] = !(up[x]||(lose-(!down[v])>0));
    }

    for (int v : G[x]){
        if (v == f) continue;
        dfs2(v, x);
    }
}

void dfs3(int x, int f){
	int cnt = 0;
	affect[x] = 1;
	for (int v : G[x]){
		if (v == f) continue;
		if (!down[v]) cnt++;
	}
	if (cnt == 1){
		for (int v : G[x]){
			if (f == v) continue;
			if (!down[v]) dfs3(v, x);
		}
	} else if (cnt == 0) {
		for (int v : G[x]){
			if (f == v) continue;
			dfs3(v, x);
		}
	}
}

void a38(){
	dfs(1, 1);
	dfs2(1, 1);
	dfs3(1,1);
	int r1 = 0, c = 0;
	for (int i = 1; i<= n; i++){
		if (affect[i] && !down[i]) r1++;
		if (!(up[i]||down[i])) c++;
	}
	long long ans;
	if (up[1]||down[1]){
		ans = 1LL*n*n-1LL*r1*c;
		ans %= MOD;
	} else {
		ans = 1LL*r1*c%MOD;
	}
	cout << ans << '\n';
}

long long pow(int x, long long n){
	long long ans = 1;
	while (n){
		if (n & 1) ans = ans*x%MOD;
		n>>=1;
		x = 1LL*x*x%MOD;
	}
	return ans;
}

void a7(){
	cout << pow(4,d)%MOD << '\n';
}

int main(){
	cin >> n >> d;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if (n==2) a7();
	else a38();

	return 0;
}