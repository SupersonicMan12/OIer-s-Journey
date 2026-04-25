#include <bits/stdc++.h>
using namespace std;

int n, q;
int pre[300005], nxt[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= q; i++){
		int c, p; cin >> c >> p;
		if (pre[c]){
			nxt[pre[c]] = 0;
		}
		pre[c] = p;
		nxt[p] = c;
	}
	for (int i = 1; i <= n; i++){
		int cnt = 0;
		int x = i;
		if (!pre[x]) {
			while (x){
				cnt++; 
				x = nxt[x];
			}
		}
		cout << cnt << ' ';
	}
	cout << endl;

	return 0;
}