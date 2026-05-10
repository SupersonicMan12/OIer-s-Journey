#include <bits/stdc++.h>
using namespace std;

int n, m, q;
long long d[100005];
int fa[100005];

int find(int x){
	if (fa[x]==x) return x;
	int rt = find(fa[x]);
	d[x] += d[fa[x]];
	return fa[x] = rt;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) fa[i]=i;
	for (int i = 1; i <= m; i++){
		int a, b; long long c; cin >> a >> b >> c; a--;
		int t1 = find(a);
		int t2 = find(b);
		// now connect a to b
		if (t1 != t2){
			d[t1] = c+d[b]-d[a];
			fa[t1] = t2;
		}
	}
	for (int i = 1; i <= q; i++){
		int a, b; cin >> a >> b; a--;
		if (find(a) != find(b)){
			cout << "UNKNOWN\n";
		} else {
			cout << d[a]-d[b] << '\n';
		}
	}
	return 0;
}



