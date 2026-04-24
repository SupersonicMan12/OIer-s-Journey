// notice permutations can be seen as matrix transformations
// also notice that inv(A) = inv(A^-1)
// then, inv(A P-1) + inv(P B-1) = inv(A P-1) + inv(B P-1)
// since P and P-1 one to one, just consider number of ways to
// minimize inv(A P) + inv(B P), with bitset dp

#include <bits/stdc++.h>
using namespace std;

int a[22], b[22];
int A[22], B[22];
int dp[1200000];
long long num[1200000];

int main(){
	freopen("inv.in", "r", stdin);
	freopen("inv.out", "w", stdout);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {cin >> a[i]; a[i]--;}
	for (int i = 0; i < n; i++) {cin >> b[i]; b[i]--;}
	int s = (1<<n)-1;
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0; num[0] = 1;
	for (int i = 0; i < s; i++){
		for (int j = 0; j < n; j++){
			A[j] = B[j] = 0;
		}
		for (int j = 0; j < n; j++){
			if ((i>>j)&1){
				A[a[j]]++;
				B[b[j]]++;
			}
		}
		for (int j = n-2; j >= 0; j--){
			A[j] += A[j+1];
			B[j] += B[j+1];
		}
		for (int j = 0; j < n; j++){
			if ((i>>j)&1) continue;
			int challenger = dp[i] + (A[a[j]]+B[b[j]]);
			if (challenger == dp[i|(1<<j)]){
				num[i|(1<<j)]+=num[i];
			} else if (challenger < dp[i|(1<<j)]){
				dp[i|(1<<j)] = challenger;
				num[i|(1<<j)]=num[i];
			}
		}
	}
	cout << num[s] << '\n';
	return 0;
}







