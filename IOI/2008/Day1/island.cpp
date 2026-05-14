#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, cnt;
int to[N+5], w[N+5];
int deg[N+5];
long long d2[N+5],d[N+5],dia[N+5];
bool vis[N+5];
int V[2*N+5];
int P[2*N+5];
long long rec[2*N+5];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> to[i] >> w[i];
		deg[to[i]]++;
	}
	queue<int> Q;
	for (int i = 1; i <= n; i++){
		if (deg[i]==0) Q.push(i);
	}
	while (!Q.empty()){
		int x = Q.front(); Q.pop();
		int v = to[x];
		vis[x] = 1;
		// cout << x << '\n';
		deg[v]--;
		long long k = d[x] + w[x];
		if (k > d[v]) d2[v] = d[v], d[v] = k;
		else if (k > d2[v]) d2[v] = k;
		dia[v] = max(dia[v], dia[x]);
		dia[v] = max(dia[v], d[v]+d2[v]);
		if (deg[v]==0) Q.push(v);
	}
	long long ans = 0;
	for (int x = 1; x <= n; x++){
		if (!vis[x]){
			long long pans = 0;
			int c = 0;
			for (int j = 1; j <= 2; j++){
				V[++c] = x;
				vis[x] = 1;
				pans = max(pans, dia[x]);
				int curr = to[x];
				while (curr != x){
					vis[curr] = 1;
					pans = max(pans, dia[curr]);
					V[++c] = curr;
					curr = to[curr];

				}
			}
			// V is created 1...c
			long long delta = 0;
			long long tans = 0;
			int circ = c/2;
			int head = 0, tail = 1;
			// cout << "#$" << endl;
			for (int i = 1; i <= c; i++){
				while (head >= tail && i-P[tail]>=circ) tail++;
				if (head >= tail) tans = max(tans, d[V[i]]+delta+rec[P[tail]]);
				rec[i] = d[V[i]]-delta;
				while (head >= tail && rec[P[head]]<=rec[i]) head--;
				P[++head] = i;
				delta += w[V[i]];
			}
			// cout << endl;
			pans = max(pans, tans);
			ans += pans;
			// cout << ans << endl;
		}
	}
	cout << ans << '\n';
}





