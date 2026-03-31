#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
string x, y, S;
int q, mx;
long long len[95];
long long phi[26][95];

long long find(long long k, int c){
	long long ans = 0;
	for (int curr = mx; curr >= 3; curr--){
		if (len[curr] <= k){
			ans += phi[c][curr];	
			k -= len[curr];
		}
	}
	for (long long i = 0; i < k; i++){
        ans += (S[i]-'a' == c);
    }
	return ans;
}

int main(){
	cin >> x;
	cin >> y;
	S = y + x;
	len[1] = x.size();
	len[2] = y.size();
	for (int i = 0; i < len[1]; i++){
		phi[x[i]-'a'][1]++;
	}
	for (int i = 0; i < len[2]; i++){
		phi[y[i]-'a'][2]++;
	}
	for (int i = 3; i <= 90; i++){
		mx = i;
		len[i] = len[i-1]+len[i-2];
		for (int j = 0; j < 26; j++){
			phi[j][i] = phi[j][i-1]+phi[j][i-2];
		}
		if (len[i] > INF) break;
	}

	cin >> q;
	for (int i = 1; i <= q; i++){
		// reduction
		long long l, r; char c; cin >> l >> r >> c;
		int cc = c-'a';
		cout << find(r, cc)-find(l-1,cc) << '\n';
	}
	return 0;
}