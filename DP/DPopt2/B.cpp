// proof of decision monotonicity
// consider a sequence of points {wi, hi} where
// hi increases, wi decreases. 
// notice w[i, j] = w[i+1] * h[j];
// Wish: 
// w[i, j] + w[i+1, j+1] - w[i, j+1] - w[i+1, j-1] <= 0;
// LHS = w[i+1] * h[j] + w[i+2] * h[j+1] - w[i+1] * h[j+1] - w[i+2] * h[j]
// 	   = (w[i+1]-w[i+2]) * (h[j]-h[j+1]) <= 0;

#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[50005];
pair<int,int> a[50005];
int ww[50005], h[50005];
struct interval{
	int l, r, x;
} q[50005];

long long w(int x, int y){
	return 1LL*ww[x+1]*h[y];
}

long long ev(int from, int to){
	return dp[from] + w(from, to);
}

// first position of i winning
int binary_search(int i, int head){
	int l = q[head].l, r = q[head].r, x = q[head].x;
	if (ev(i,r) > ev(x,r)) return r+1;
	while (l < r){
		int mid = (l+r)>>1;
		if (ev(i,mid) <= ev(x,mid)) r = mid;
		else l = mid+1;
	}
	return l;
}

int main(){
	cin >> n ;
	for (int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a+1, a+1+n);
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		while (cnt && ww[cnt] <= a[i].second) cnt--;
		h[++cnt] = a[i].first;
		ww[cnt] = a[i].second;
	}

	int head = 1, tail = 1;
	q[1] = {1,cnt,0};
	for (int i = 1; i <= cnt; i++){
		int j = q[tail].x;
		dp[i] = dp[j] + w(j,i); 
		while (head >= tail && ev(q[head].x, q[head].l) >= ev(i, q[head].l)){
			head--;
		}
		// right now head is not completely winning
		// u is first position still winning
		int u = binary_search(i, head);
		if (u <= cnt){
			q[head].r = u-1;
			q[++head] = {u, cnt, i};
		}
		if (i == q[tail].r) tail++;
	}
	cout << dp[cnt] << '\n';

	return 0;
}


// best transitions 00000000
// then 			00001111
// then 			00001122


