#include <bits/stdc++.h>
using namespace std;

string S, T;
int s, t;

int main(){
	cin >> S; cin >> T;
	s = S.length(); t = T.length();
	S = "#" + S; T = "#" + T;
	long long ans = 0;
	for (int i = 1; i <= s; i++){
		int pos = i;
		for (int j = t; j >= 1; j--){
			while (pos > 0 && S[pos] != T[j]){
				pos--;
			}
			if (pos == 0) {
				pos = -1;
				break;
			}
			pos--;
		}
		if (pos == -1) continue;
		ans += pos+1;
	}
	ans = 1LL*s*(s+1)/2-ans;
	cout << ans << '\n';

	return 0; 
}