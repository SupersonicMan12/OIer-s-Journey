#include <bits/stdc++.h>
using namespace std;

/* 
Let L' = L+1, used as L simply
Let SS[x] = x + S[x], used as S[x] simply
dp[x] = MIN(j < x){
	dp[j] + (S[x]-S[j]-L')^2
}
satisfies Decision Monotonicity via (easily)

w[i,j+1] + w[i+1,j] >= w[i,j]+w[i+1, j+1]
*/

// from l to r the opt() is x
struct interval{
	int l, r, x;
	interval(){} //default needed for stk
	interval(int _l, int _r, int _x): l(_l), r(_r), x(_x){}
} stk[50005];

int n,L,head,tail;
long long dp[50005];
long long c[50005];

long long w(int i, int j){
	return (c[j]-c[i]-L)*(c[j]-c[i]-L);
}

// first smaller in ge ge ge < < <
long long findx(int i){
	int l = stk[head].l, r = stk[head].r, x = stk[head].x, mid;
	if (dp[i] + w(i,r) >= dp[x] + w(x,r)) return r+1;
	while (l < r){
		mid = (l+r)>>1;
		if (dp[i] + w(i,mid) < dp[x] + w(x,mid)) r = mid;
		else l = mid+1;
	}
	return l;
}

int main(){
	cin >> n >> L; L++;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		c[i] += c[i-1]+1;
	}
	stk[head=tail=1] = interval(1,n,0);
	for (int i = 1; i<= n; i++){
		// tail is current transition from
		dp[i] = dp[stk[tail].x] + w(stk[tail].x, i);
		// while larger end replaceable...
		while (i < stk[head].l && dp[i] + w(i, stk[head].l)<dp[stk[head].x]+w(stk[head].x, stk[head].l)) 
			head--;
		// u = stk[head].r + 1 if this segment fails completely 
		int u = findx(i); 
		stk[head].r = u-1;
		// if n+1 results, then then not used
		if (u <= n) stk[++head] = interval(u,n,i);
		// if this is the last timestamp of current interval, next.
		if (i == stk[tail].r) tail++;
	}
	cout << dp[n] << endl;

	return 0;
}


// best transition always 11112222333344445555...
// 1: 1-5
// 2: 6-12
// 3: 13-14
// 4: 15-16
// 5: inserting... 
// if [5,15] < [4,15], then remove that
// if [5,13] < [3,13], then remove that
// suppose [5,6] >= [2,6], we check from where 5 overrides 2
// e.g. 2222 -> 2555, 2255, 2225 etc.





