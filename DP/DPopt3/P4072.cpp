// Variance * M^2
// sum((x-xbar)^2)/M*M^2
// sum((x-xbar)^2)*M
// M*sum((x-xbar)^2), xbar is known constant C = sum/M
// M*sum(x-c)^2
// total sum <= 30000. n <= 3000.
// T = sum = M*C;

// dp[0][0] = 0;
// dp[i][j] = up to i taken, j elements. #states = 6e6
// construct layer by layer (i)
// dp[i][j] = min(k < j) (dp[i-1][k] + M*(sum[j]-sum[k]-C)^2)
// strip C^2 and count that as M mandatory contributions
// dp[k]+M*sk^2+2T(sk)+(M*sj^2-2T(sj))-2*M*sj*sk
// help[k] = dp[k]+sk^2+2C(sk);
// store line k with yinte help[k] and slope (-2sk)
// to obtain dp add the mandatory (sj^2-2C(sj))

#include <bits/stdc++.h>
using namespace std;



int main(){

	return 0;
}
