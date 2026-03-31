#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int current[26];
string S;

int main(){
	cin >> n >> l >> r;
	cin >> S;
	long long ans = 0;
	for (int i = 0; i < n; i++){
		if (i >= l){
			current[S[i-l]-'a']++;
		}
		if (i > r){
			current[S[i-r-1]-'a']--;
		}
		ans += current[S[i]-'a'];
	}
	cout << ans << '\n';
}