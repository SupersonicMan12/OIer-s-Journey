// full solution to paint 

#include <bits/stdc++.h>
using namespace std;

int p[200005];
bool dpl[200005][102];
bool dpr[200005][102];

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
		dpr[i][0] = flag;
	}

	dpl[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			int c = C[j];
			if (i >= c && dpl[i-c][j-1])
			if (s[i+1] != 'X' && p[i]==p[i-c]){
				dpl[i+1][j]=1;
			}
		}
		if (s[i] == 'X'){
			for (int j = 1; j <= k; j++){
				dpl[i][j]=0;
			}
		}
		for (int j = 1; j <= k; j++){
			dpl[i+1][j] = dpl[i][j];
		}
		for (int j = 0; j <= k; j++){
			cout << dpl[i][j] << ' ';
		}
		cout << endl;
	}
	return ":";
}


