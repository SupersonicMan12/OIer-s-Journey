#include <bits/stdc++.h>
using namespace std;

int n, q, x[300005];
const int INF = 1e9;
const int N = 9e6;
int nxt[N][2];
int who[N];
int cnt;

int main(){
	freopen("function.in", "r", stdin);
	freopen("function.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	memset(who, 0x3f, sizeof(who));
	for (int j = 1; j <= n; j++){
		cin >> x[j];
		int p = 0;
		for (int i = 29; i >= 0; i--){
			int bt = (x[j]>>i)&1;
			if (!nxt[p][bt]) nxt[p][bt] = ++cnt;
			p = nxt[p][bt];
			who[p] = min(who[p],j);
		}
	}
	for (int i = 1; i <= q; i++){
		int a, b; cin >> a >> b;
		int p1=INF, p2=INF;
		// p1 = smallest position with a^x<=b
		// p2 = smallest position with a^x>=b
		int p = 0;
		for (int i = 29; i >= 0; i--){
			if ((b>>i)&1){
				int lo = (a>>i)&1;
				if (nxt[p][lo])
				p1 = min(p1, who[nxt[p][lo]]);
				if (!nxt[p][1-lo]) break;
				p = nxt[p][1-lo];
			} else {
				if (!nxt[p][(a>>i)&1]) break;
				p = nxt[p][(a>>i)&1];
			}
			if (i == 0) p1 = min(p1, who[p]);
		}
		p = 0;
		for (int i = 29; i >= 0; i--){
			if (((b>>i)&1)^1){
				int lo = ((a>>i)&1)^1;
				if (nxt[p][lo])
				p2 = min(p2, who[nxt[p][lo]]);
				if (!nxt[p][1-lo]) break;
				p = nxt[p][1-lo];
			} else {
				if (!nxt[p][((a>>i)&1)^1]) break;
				p = nxt[p][((a>>i)&1)^1];
			}
			if (i == 0) p2 = min(p2, who[p]);
		}
		if (p1==INF || p2==INF){
			cout << -1 << '\n';
		} else if (p1 == p2){
			cout << p1 << '\n';
		} else {
			cout << max(p1,p2)-1 << '\n';
		}
	}


	return 0;
}




