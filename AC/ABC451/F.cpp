#include <bits/stdc++.h>
using namespace std;

int n, ans, q;
int fa[200005];
int color[200005];
int szw[200005],szb[200005];
int find(int x){
	if (fa[x]==x) return x;
	return fa[x] = find(fa[x]);
}
int main(){
	cin >> n >> q; ans = n;
	int (int i = 1; i <= n; i++) {
		fa[i]=i;
		color[i]=1; // white
		szw[i]=1;
		swb[i]=0;
	}
	bool flag = 0;
	for (int i = 1; i <= q; i++){
		int x, y; cin >> x >> y;
		// x and y must be different colors, maximize white 
		if (find(x)==find(y)){
			if (color[x]==color[y]){
				flag = 1;
			}
		} else {
			if (color[x]==color[y]){
				if (szw[x]+swb[x]>swx[y]+swb[y]){
					toggle
				}
			}
		}	
		if (flag) cout << -1 << '\n';
		else cout << ans << '\n';
	}

	return 0;
}



