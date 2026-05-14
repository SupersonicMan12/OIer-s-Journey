#include <bits/stdc++.h>
using namespace std;

int S[100005];
int n;
// best of first i with [mask1][mask2] as previous 2
int dp[2][4][4][4][4];

void mx(int &x, int y){
	if (y > x) x = y;
}

int ck(int x, int y, int z){
	int M[4];
	M[0] = M[1] = M[2] = M[3] = 0;
	M[x] = M[y] = M[z] = 1;
	return M[1]+M[2]+M[3];
}

int main(){
	cin >> n; string T;
	cin >> T; T = "$"+T;
	for (int i = 1; i <= n; i++){
		if (T[i]=='M') S[i] = 1;
		if (T[i]=='B') S[i] = 2;
		if (T[i]=='F') S[i] = 3;
	}
	memset(dp[0], 0xc0, sizeof(dp[0]));
	dp[0][0][0][0][0] = 0;
	for (int i = 1; i <= n; i++){
		memset(dp[1], 0xc0, sizeof(dp[1]));
		int c = S[i];
		for (int p1 = 0; p1 <= 3; p1++){
		for (int p2 = 0; p2 <= 3; p2++){
			if (!p1 && p2) continue;
			for (int o1 = 0; o1 <= 3; o1++){
			for (int o2 = 0; o2 <= 3; o2++){
				if (!o1 && o2) continue;
				mx(dp[1][p1][c][o2][o1], dp[0][p2][p1][o2][o1]+ck(p1,p2,c));
				mx(dp[1][p2][p1][o1][c], dp[0][p2][p1][o2][o1]+ck(o1,o2,c));
			}
			}
		}
		}
		memcpy(dp[0], dp[1], sizeof(dp[0]));
	}
	int ANS = -1999999;
	for (int p1 = 0; p1 <= 3; p1++)
	for (int p2 = 0; p2 <= 3; p2++){
		if (!p1 && p2) continue;
		for (int o1 = 0; o1 <= 3; o1++)
		for (int o2 = 0; o2 <= 3; o2++){
			if (!o1 && o2) continue;
			ANS = max(ANS,dp[0][p2][p1][o2][o1]);
		}
	}
	cout << ANS << '\n';

	return 0;
}