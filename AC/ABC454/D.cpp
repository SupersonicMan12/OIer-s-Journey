#include <bits/stdc++.h>
using namespace std;

string S, T;

string reduce(string s){
	string ans;
	for (char c : s){
		ans.push_back(c);
		while ((int)ans.size()>=4){
			int k = ans.size();
			if (ans[k-1]==')'&&ans[k-2]=='x'&&ans[k-3]=='x'&&ans[k-4]=='('){
				ans.pop_back(); ans.pop_back(); ans.pop_back(); ans.pop_back();
				ans.push_back('x'); ans.push_back('x'); 
			} else {
				break;
			}
		}
	}
	return ans;
}

void solve(){
	cin >> S;
	cin >> T;
	S = reduce(S);
	T = reduce(T);
	if (S == T) cout << "Yes\n";
	else cout << "No\n";
}

int main(){
	int t; cin >> t;
	while (t--) solve();

	return 0;
}