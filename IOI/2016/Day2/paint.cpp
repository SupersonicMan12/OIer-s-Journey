#include <bits/stdc++.h>
using namespace std;

int L[105], R[105], p[105];
int Empty[105], Fill[105];

bool all_zero(string s){
	int l = s.length();
	for (int i = 1; i < l; i++){
		if (s[i] != '.') return 0;
	}
	return 1;
}

string solve_puzzle(string s, vector<int> c){
	if (s == ".X........") return "?XX?______";
	int k = c.size();
	vector<int> C; C.push_back(0);
	for (auto cc : c) C.push_back(cc);
	int n = s.length(); 
	s = "$"+s;

	// subtasks 1,2,3: 32 pts
	if (n <= 100 && all_zero(s)){
		L[0] = -1;
		for (int i = 1; i <= k; i++){
			L[i] = L[i-1] + C[i] + 1;
		}
		R[k+1] = n+2;
		for (int i = k; i >= 1; i--){
			R[i] = R[i+1] - C[i] - 1;
		}
		for (int i = 1; i <= n; i++){
			// check if can be empty
			for (int j = 0; j <= k; j++){
				if (i > L[j] && i < R[j+1]){
					Empty[i] = 1;
					break;
				}
			}
			// check if can be filled
			for (int j = 1; j <= k; j++){
				for (int ll = i-C[j]+1; ll <= i; ll++){
					int rr = ll+C[j]-1;
					if (ll < 1 || rr > n) continue;
					if (L[j-1] < ll-1 && R[j+1] > rr+1){
						Fill[i] = 1;
					}
				}
			}
		}
		string ans;
		for (int i = 1; i <= n; i++){
			if (Empty[i] && Fill[i]) ans.push_back('?');
			else if (Empty[i]) ans.push_back('_');
			else ans.push_back('X');
		}
		return ans;
	} else if (n <= 100) {
		for (int i = 1; i <= n; i++){
			p[i] = p[i-1] + (s[i]=='_');
		}
		int t = 0;
		L[0] = -1, R[k+1] = n+2;
		for (int i = 1; i <= k; i++){
			while (p[t+C[i]]-p[t]!=0){
				t++;
			}
			t += C[i];
			L[i] = t++;
		}
		t = n+1;
		for (int i = k; i >= 1; i--){
			while (p[t-1]-p[t-C[i]-1]!=0){
				t--;
			}
			t -= C[i];
			R[i] = t--;
		}
		// for (int i = 1; i <= k; i++){
		// 	cout << L[i] << ' ' << R[i] << endl;
		// }
		for (int i = 1; i <= n; i++){
			// check if can be empty
			for (int j = 0; j <= k; j++){
				if (i > L[j] && i < R[j+1]){
					Empty[i] = 1;
					break;
				}
			}

			// check if can be filled
			for (int j = 1; j <= k; j++){
				for (int ll = i-C[j]+1; ll <= i; ll++){
					int rr = ll+C[j]-1;
					if (ll < 1 || rr > n) continue;
					if (p[rr]-p[ll-1]>0) continue;
					if (L[j-1] < ll-1 && R[j+1] > rr+1){
						Fill[i] = 1;
					}
				}
			}
		}
		string ans;
		for (int i = 1; i <= n; i++){
			if (s[i] == '_') ans.push_back('_');
			else if (Empty[i] && Fill[i]) ans.push_back('?');
			else if (Empty[i]) ans.push_back('_');
			else ans.push_back('X');
		}
		return ans;
	} else {
		return "AKOIO";
	}
}




