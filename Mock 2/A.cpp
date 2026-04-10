#include <bits/stdc++.h>
using namespace std;
int n, H;
int w[1000005], h[1000005];
int l[1000005], r[1000005];
int ll[1000005], rr[1000005];
int cl[1000005], cr[1000005];
int p[1000005];

bool sp(int x, int y){ 
	return h[x] < h[y] || (h[x] == h[y] && x < y); 
}

int main(){
	freopen("ex_poster.in", "r", stdin);
	freopen("ex_poster.ans", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> H;
	for (int i = 1; i <= n; i++){
		cin >> h[i] >> w[i];
		w[i] += w[i-1];
	}
	for (int i = 1; i <= n; i++) p[i]=i;
	sort(p+1, p+n+1, sp);
	set<int> I;
	I.insert(0); I.insert(-1);
	I.insert(n+1); I.insert(n+2);
	for (int i = 1; i <= n; i++){
		auto idx = lower_bound(I.begin(), I.end(), i);
		l[p[i]] = *(--idx);
		ll[p[i]] = *(--idx);
		idx++;
		r[p[i]] = *(++idx);
		rr[p[i]] = *(++idx);
		I.insert(i);
	}
	for (int i = 1; i <= n; i++){
		if (l[i]==-1) l[i] = 0;
		if (ll[i]==-1) ll[i] = 0;
		if (r[i]==n+2) r[i] = n+1;
		if (rr[i]==n+2) rr[i] = n+1;
	}

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
