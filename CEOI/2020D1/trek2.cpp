#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
vector<int> G[100005];
int n; long long d;
bool dp[100005];
int R[100005], s[100005], SR[100005][2];
int Rfinal[100005], dpfinal[100005];
int c;
long long T[2][2];
long long S[2][2];

void mul(long long A[2][2], long long B[2][2], long long C[2][2]){
    long long X[2][2];
    X[0][0] = (A[0][0]*B[0][0] + A[0][1]*B[1][0]) % MOD;
    X[0][1] = (A[0][0]*B[0][1] + A[0][1]*B[1][1]) % MOD;
    X[1][0] = (A[1][0]*B[0][0] + A[1][1]*B[1][0]) % MOD;
    X[1][1] = (A[1][0]*B[0][1] + A[1][1]*B[1][1]) % MOD;
    memcpy(C, X, sizeof(X));
}

void dfs1(int x, int f){
	for (int v : G[x]){
		if (v ==f)continue;
		dfs1(v, x);
		s[x] += !dp[v];
		SR[x][dp[v]] += R[v];
	}
	if (s[x] > 0) dp[x] = 1;
	if (s[x]==1) R[x] = SR[x][0];
	else if (s[x]==0) R[x] = (SR[x][1]+1);
}

// dependencies downstairs done
// for each u, v reverse relationship temporarily
void dfs2(int x, int f){
	if (!dp[x]) c++;
	Rfinal[x] = R[x];
	dpfinal[x] = dp[x];
	for (int v : G[x]){
		if (v == f) continue;
		int tru = R[x], tsu = s[x], trs0u = SR[x][0], trs1u = SR[x][1]; bool dpu = dp[x];
		int trv = R[v], tsv = s[v], trs0v = SR[v][0], trs1v = SR[v][1]; bool dpv = dp[v];

		// remove v as x's child, reevaluate
		s[x] -= !dp[v];
		SR[x][dp[v]] -= R[v];
		dp[x] = (s[x] > 0);
		if (s[x]==1) R[x] = SR[x][0];
		else if (s[x]==0) R[x] = (SR[x][1]+1);
		else R[x] = 0;
		// add x as v's child, reevalaute:
		s[v] += !dp[x];
		SR[v][dp[x]] += R[x];
		dp[v] = (s[v] > 0);
		if (s[v]==1) R[v] = SR[v][0];
		else if (s[v]==0) R[v] = (SR[v][1]+1);
		else R[v] = 0;

		dfs2(v, x);
		R[x] = tru, s[x] = tsu, SR[x][0] = trs0u, SR[x][1] = trs1u; dp[x] = dpu;
		R[v] = trv, s[v] = tsv, SR[v][0] = trs0v, SR[v][1] = trs1v; dp[v] = dpv;
	}
}

int main(){
	cin >> n >> d;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs1(1,1);
	dfs2(1,1);
	for (int i = 1; i <= n; i++){
		if (dpfinal[i]==0){
			(T[0][0] += n-Rfinal[i])%=MOD;
			(T[0][1] += n)%=MOD;
			(T[1][0] += Rfinal[i])%=MOD;
		} else {
			(T[0][0] += Rfinal[i])%=MOD;
			(T[1][0] += n-Rfinal[i])%=MOD;
			(T[1][1] += n)%=MOD;
		}
	}
	d--;
	S[0][0] = S[1][1] = 1;
	while (d){
	    if (d & 1) mul(S, T, S);
	    mul(T, T, T);
	    d >>= 1;
	}
	long long ans, f0 = (1LL*c*S[0][0] + 1LL*(n-c)*S[0][1])%MOD, f1 = (1LL*c*S[1][0] + 1LL*(n-c)*S[1][1])%MOD;
	if (dpfinal[1]){
		ans = 1LL*n*f1+1LL*(n-Rfinal[1])*f0;
		ans %= MOD;
	} else {
		ans = 1LL*Rfinal[1]*f0%MOD;
	}
	cout << ans << '\n';

	return 0;
}



