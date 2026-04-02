#include <bits/stdc++.h>
using namespace std;
 
// 0: factor, 1: term, 2: expression
string dp[40][256][3];
string ans[256];
int can[256][3];
const int L = 38;

int main(){
	dp[1][15][0] = dp[1][15][1] = dp[1][15][2] = "x";
	dp[1][51][0] = dp[1][51][1] = dp[1][51][2] = "y";
	dp[1][85][0] = dp[1][85][1] = dp[1][85][2] = "z";
	memset(can, 0x3f, sizeof(can));
	can[15][0]=can[15][1]=can[15][2]=1;
	can[51][0]=can[51][1]=can[51][2]=1;
	can[85][0]=can[85][1]=can[85][2]=1;

	for (int len = 2; len <= L; len++){
		// !F -> F
		for (int i = 0; i <= 255; i++){
			if (len > can[i][0]) continue;
			if (dp[len-1][255^i][0]=="") continue;
			string cand = "!" + dp[len-1][255^i][0];
			if (dp[len][i][0]=="" || cand < dp[len][i][0]){
				dp[len][i][0] = cand;
				can[i][0] = len;
			}
		}
		// (E) -> F
		for (int i = 0; i <= 255; i++){
			if (len > can[i][0]) continue;
			if (dp[len-2][i][2]=="") continue;
			string cand = "(" + dp[len-2][i][2] + ")";
			if (dp[len][i][0]=="" || cand < dp[len][i][0]){
				dp[len][i][0] = cand;
				can[i][0] = len;
			}
		}
		// (T & F) -> T
		for (int a = 1; a < len-1; a++){
			int b = len-1-a;
			for (int m1 = 0; m1 <= 255; m1++){
				if (dp[a][m1][1]=="") continue;
				for (int m2 = 0; m2 <= 255; m2++){
					if (dp[b][m2][0]=="") continue;
					int m = m1&m2;
					if (len > can[m][1]) continue;
					string cand = dp[a][m1][1] + "&" + dp[b][m2][0];
					if (dp[len][m][1]=="" || cand < dp[len][m][1]){
						dp[len][m][1] = cand;
						can[m][1] = len;
					}
				}
			}
		}

		// E | T -> E
		for (int a = 1; a < len-1; a++){
			int b = len-1-a;
			for (int m1 = 0; m1 <= 255; m1++){
				if (dp[a][m1][2]=="") continue;
				for (int m2 = 0; m2 <= 255; m2++){
					if (dp[b][m2][1]=="") continue;
					int m = m1|m2;
					if (len > can[m][2]) continue;
					string cand = dp[a][m1][2] + "|" + dp[b][m2][1];
					if (dp[len][m][2]=="" || cand < dp[len][m][2]){
						dp[len][m][2] = cand;
						can[m][2] = len;
					}
				}
			}
		}		

		// propagate:
		for (int i = 0; i <= 255; i++){
			if (dp[len][i][0]!=""){
				if (dp[len][i][1]=="" || dp[len][i][0]<dp[len][i][1]){
					dp[len][i][1] = dp[len][i][0];
					can[i][1] = len;
				}
			}	
			if (dp[len][i][1]!=""){
				if (dp[len][i][2]=="" || dp[len][i][1]<dp[len][i][2]){
					dp[len][i][2] = dp[len][i][1];
					can[i][2] = len;
				}
			}	
		}
	}

	// answers are in expression:
	for (int i = 0; i <= 255; i++){
		for (int len = 1; len <= L; len++){
			if (dp[len][i][2] != ""){
				ans[i] = dp[len][i][2];
				break;
			}
		}
	}

	int q; cin >> q;
	while (q--){
		char c;
		int x = 0;
		for (int i = 7; i >= 0; i--){
			cin >> c;
			int bit = (c=='1')?1:0;
			x += bit<<i;
		}
		cout << ans[x] << '\n'; 
	}

	return 0 ;
}





