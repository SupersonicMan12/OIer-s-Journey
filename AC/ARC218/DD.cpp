#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[200005];
int blockstart[200005];
int block[200005];
int nxt[200005][18];

int bin(int l, int r, int x){
	// l = the smallest <= x;
	// false false true true true
	r++;
	while (l < r){
		int mid = (l+r)>>1;
		if (a[mid] <= x) r = mid;
		else l = mid+1;
	}
	return l-1;
}

int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	a[n+1] = 200002;
	int cnt = 0;
	for (int i = 1; i <= n+1; i++){
		if (a[i] > a[i-1]){
			blockstart[++cnt] = i;
		}
		block[i] = cnt;
	}
	blockstart[++cnt] = n+2;
	block[n+2] = cnt;
	for (int i = 1; i <= n; i++){
		int endnxt = blockstart[block[i]+2]-1;
		int beginnxt = blockstart[block[i]+1];
		if (a[beginnxt] > a[i]){
			int x = bin(beginnxt, endnxt, a[i]);
			nxt[i][0] = x;
		} else {
			nxt[i][0] = beginnxt-1;
		}
	}
	nxt[n+1][0] = n+1;
	for (int i = 1; i <= 17; i++){
		for (int j = 1; j <= n+1; j++){
			nxt[j][i] = nxt[nxt[j][i-1]][i-1];
		}
	}
	for (int i = 1; i <= q; i++){
		int l, r ; cin >> l >> r;
		if (block[l]==block[r]){
			cout << 1 << '\n';
			continue;
		}
		int br = block[r];
		int x = blockstart[block[l]+1]-1;
		int ans = 1;
		for (int i = 17; i >= 0; i--){
			if (block[nxt[x][i]] < br){
				ans += (1<<i);
				x = nxt[x][i];
			}
		}
		cout << ans+1 << '\n';
	}
	return 0;
}




