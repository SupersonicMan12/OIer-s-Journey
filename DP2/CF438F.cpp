// https://codeforces.com/contest/868/problem/F

#include <bits/stdc++.h>
using namespace std;

int n, k;
long long dp[2][100005];
int opt[100005];
int freq[100005];
int a[100005], l, r;
long long C;

void MN(long long &x, long long y){
	if (x > y) x = y;
}

long long cost(int L, int R){
	while (l > L) {
		l--; 
		C += freq[a[l]];
		freq[a[l]]++;
	}
	while (r < R) {
		r++; 
		C += freq[a[r]];
		freq[a[r]]++;
	}
	while (l < L){
		C -= (freq[a[l]]-1);
		freq[a[l]]--;
		l++;
	}
	while (r > R){
		C -= (freq[a[r]]-1);
		freq[a[r]]--;
		r--;
	}
	return C;
}

void DC(int l, int r, int opl, int opr, int i){
	if (l > r) return;
	// brute force pivot mid:
	int mid = (l+r)>>1;
	for (int x = opl; x <= opr; x++){
		// cout << x+1 << ' ' << mid << ' ' << cost(x+1, mid) << endl;
		long long cand = dp[0][x]+cost(x+1, mid);
		if (dp[1][mid] > cand){
			dp[1][mid] = cand;
			opt[mid] = x;
		}
	}
	if (l == r) return;	
	DC(l, mid-1, opl, opt[mid], i);
	DC(mid+1, r, opt[mid], opr, i);
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		C += (freq[a[i]]);
		freq[a[i]]++;
		// cout << C << endl;
	}
	l = 1, r = n;
	memset(dp[0], 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= k; i++){
		memset(dp[1], 0x3f, sizeof(dp[1]));
		DC(1, n, 0, n-1, i);
		memcpy(dp[0], dp[1], sizeof(dp[0]));
	}
	cout << dp[0][n] << endl;

	return 0;
}
