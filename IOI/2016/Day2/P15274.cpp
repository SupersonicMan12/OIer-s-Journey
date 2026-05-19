#include <bits/stdc++.h>
using namespace std;
extern "C"
{
	string solve_puzzle(string s, vector<int> c);
}
int p[200005];
bool dpl[200005][102];
bool dpr[200005][102];
bool Empty[200005];
int Filled[200005];

string solve_puzzle(string s, vector<int> CC){
	int k = CC.size();
	vector<int> C; C.push_back(0);
	for (auto cc : CC) C.push_back(cc);
	int n = s.length(); 
	s = "$"+s;

	bool flag = 1;
	for (int i = 1; i <= n; i++){
		p[i] = p[i-1] + (s[i]=='_');
		if (s[i]=='X') flag = 0;
		dpl[i][0] = flag;
	}

	flag = 1;
	for (int i = n; i >= 1; i--){
		if (s[i]=='X') flag = 0;
		dpr[i][k+1] = flag;
	}	

	dpl[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			int c = C[j]+1;
			if (i >= c && dpl[i-c][j-1])
			if (s[i] != 'X' && p[i-1]==p[i-c]){
				dpl[i][j]=1;
			}
		}
		if (s[i+1] != 'X'){
			for (int j = 1; j <= k; j++){
				dpl[i+1][j] = dpl[i][j];
			}
		}
		
		// cout << i << ":";
		// for (int j = 0; j <= k; j++){
		// 	cout << dpl[i][j] << ' ';
		// }
		// cout << endl;
	}

	dpr[n+1][k+1] = 1;
	for (int i = n; i >= 1; i--){
		for (int j = 1; j <= k; j++){
			int c = C[j]+1;
			if (i+c-1 <= n && dpr[i+c][j+1])
			if (s[i] != 'X' && p[i+c-1]==p[i]){
				dpr[i][j]=1;
			}
		}
		if (s[i-1] != 'X'){
			for (int j = 1; j <= k; j++){
				dpr[i-1][j] = dpr[i][j];
			}
		}
		
		// cout << i << ":";
		// for (int j = 1; j <= k+1; j++){
		// 	cout << dpr[i][j] << ' ';
		// }
		// cout << endl;
	}

	// empty check:

	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= k; j++){
			if (dpl[i][j] && dpr[i][j+1]){
				Empty[i] = 1;
				break;
			}
		}
	}

	for (int j = 1; j <= k; j++){
		int c = C[j];
		for (int i = 1; i+c-1 <= n; i++){
			// check [i, i+c-1]
			if (p[i+c-1]==p[i-1]){
				if (dpl[i-1][j-1] && dpr[i+c][j+1]){
					Filled[i]++; Filled[i+c]--;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++){
		Filled[i] += Filled[i-1];
	}
	string ans; 
	for (int i = 1; i <= n; i++){
		// cout << Empty[i] << Filled[i] << '\n';
		if (Filled[i] && Empty[i]) ans.push_back('?');
		else if (Filled[i]) ans.push_back('X');
		else ans.push_back('_');
	}
	return ans;
}