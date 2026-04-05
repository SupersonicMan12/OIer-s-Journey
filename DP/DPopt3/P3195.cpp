// done again with slope optimization
// same as DPopt2/A.cpp

// take L++ and s[i] = sum c[i] + i; 
// dp[i] = j < i MIN(dp[j]+(s[i]-s[j]-L)^2)
// MIN( dp[j] + s[j]^2 + 2Ls[j] - 2s[j] * s[i]) + L^2 + s[i]^2 - 2Ls[i]
// For j consider line y = (-2s[j])x + (dp[j] + s[j]^2 + 2Ls[j]). 
// These lines decrease in slope, we want minimum, 

// dp[0] = 0;

#include <bits/stdc++.h>
using namespace std;

int n; long long L;
long long s[50005];
__int128 dp[50005];
__int128 help[50005];
int q[50005];

// y = (-2s[i])x + help[j]. 
// y = (-2s[j])x + help[i]. 
// (2s[i]-2s[j])x = help[j]-help[i]
// x = help(j-i) / 2 / s[i-j]

__int128 find(int j, int x){
	return (__int128)(-2)*s[j]*s[x] + help[j];
}

// decreasing in slope
bool check(int i, int j, int k){
	// x[ik] <= x[jk]
	return (help[i]-help[k]) * (s[j]-s[k]) <= (help[j]-help[k]) * (s[i]-s[k]);
}

int main(){
	cin >> n >> L; L++;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] += (s[i-1]+1);
	}
	int head = 1, tail = 1;
	q[1] = 0;
	for (int i = 1; i <= n; i++){
		while (head > tail && find(q[tail], i) > find(q[tail+1], i)) tail++;
		dp[i] = find(q[tail], i) + L*L - (__int128)L*2*s[i] + (__int128)s[i]*s[i];
		help[i] = (__int128) s[i]*s[i] + dp[i] + 2LL*L*s[i];
		// check has decreasing in slope
		while (head > tail && check(i,q[head],q[head-1])) head--;
		q[++head] = i;
	}
	cout << (long long)dp[n] << '\n';


	return 0;
}




