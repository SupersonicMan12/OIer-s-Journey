#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
string s; int n;

int main(){
	cin >> s;
	n = s.length();
	s = "#"+s;
	int last = 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		if (s[i]==s[i-1]){
			last = i;
		}
		ans += (i-last+1);
	}
	ans %= MOD;
	cout << ans << '\n';
	return 0;
}