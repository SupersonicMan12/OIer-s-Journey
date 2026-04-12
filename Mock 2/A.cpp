#include <bits/stdc++.h>
using namespace std;
int n, H;
long long w[1000005];
int h[1000005];
int l[1000005], r[1000005];
int ll[1000005], rr[1000005];
long long cl[1000005], cr[1000005];
int links[1000005], rechts[1000005];
vector<int> G[1000005];

void Delete(int x){
	links[rechts[x]] = links[x];
	rechts[links[x]] = rechts[x];
}

int main(){
	freopen("poster.in", "r", stdin);
	freopen("poster.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> H;
	int hmax = 0;
	for (int i = 1; i <= n; i++){
		cin >> h[i] >> w[i];
		hmax = max(hmax, h[i]);
		w[i] += w[i-1];
		G[h[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++){
		links[i] = i-1;
		rechts[i] = i+1;
	}
	for (int i = hmax; i >= H+1; i--){
		for (int v : G[i]) Delete(v);
		for (int v : G[i]){
			l[v] = links[v];
			r[v] = rechts[v];
		}
	}
	for (int i = H; i >= 1; i--){
		for (int v: G[i]) Delete(v);
		for (int v : G[i]){
			l[v] = links[v];
			r[v] = rechts[v];
			ll[v] = (links[v]==0)?0:links[links[v]];
			rr[v] = (rechts[v]==n+1)?n+1:rechts[rechts[v]];
		}
	}
	// for (int i = 1; i <= n; i++){
	// 	cout << ll[i] << rr[i] << '\n';
	// }
	long long ans = 0;
	// case 1: original
	for (int i = 1; i <= n; i++){
		ans = max(ans, 1LL*h[i]*(w[r[i]-1]-w[l[i]]));
	}
	// case 2: lifting someone to H, rect_height = H
	for (int i = 1; i <= n; i++){
		if (h[i] >= H) cl[i] = cl[i-1]+w[i]-w[i-1];
		else cl[i] = 0;
	}
	for (int i = n; i >= 1; i--){
		if (h[i] >= H) cr[i] += cr[i+1]+w[i]-w[i-1];
		else cr[i] = 0;
	}
	for (int i = 1; i <= n; i++){
		ans = max(ans, 1LL*(cl[i-1]+cr[i+1]+w[i]-w[i-1])*H);
	}
	// case 3: h[i] <= H, wider rect after lifting someone else
	for (int i = 1; i <= n; i++){
		if (h[i] <= H){
			ans = max(ans, 1LL*(w[rr[i]-1]-w[l[i]])*h[i]);
			ans = max(ans, 1LL*(w[r[i]-1]-w[ll[i]])*h[i]);
		}
	}
	cout << ans << '\n';

	return 0;
}




/*
// finding left and right
	vector<int> stk, stk2;
	stk.push_back(0);
	stk2.push_back(0);
	for (int i = 1; i <= n; i++){
		while (h[stk.back()] >= h[i]) stk.pop_back();
		while (h[stk2.back()] > h[i]) stk2.pop_back();
		l[i] = stk.back();
		ll[i] = stk2.back();
		stk.push_back(i);
		stk2.push_back(i);
	}
	stk.clear();

	stk.push_back(n+1);
	stk2.push_back(n+1);
	for (int i = n; i >= 1; i--){
		while (h[stk.back()] >= h[i]) stk.pop_back();
		while (h[stk2.back()] > h[i]) stk2.pop_back();
		r[i] = stk.back();
		rr[i] = stk2.back();
		stk.push_back(i);
		stk2.push_back(i);
	}
*/
