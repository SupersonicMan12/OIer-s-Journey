#include <bits/stdc++.h>
using namespace std;

int n; 
int p[200005][3];
map<int,int> AB;
map<int,int> AC;
map<int,int> BC;
map<pair<int,int>, int> ABC;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	AB[0]++;
	AC[0]++;
	BC[0]++;
	ABC[{0, 0}]++;
	for (int i = 1; i <= n; i++){
		char c; cin >> c;
		p[i][0]=p[i-1][0];
		p[i][1]=p[i-1][1];
		p[i][2]=p[i-1][2];
		p[i][c-'A']++;
		AB[p[i][0]-p[i][1]]++;
		BC[p[i][1]-p[i][2]]++;
		AC[p[i][0]-p[i][2]]++;
		pair<int,int> pp = {p[i][0]-p[i][1], p[i][0]-p[i][2]};
		ABC[pp]++;
	}
	long long ans = 1LL*n*(n+1)/2;
	for (auto [u, v]: AB){
		ans -= 1LL*v*(v-1)/2;
	}
	for (auto [u, v]: BC){
		ans -= 1LL*v*(v-1)/2;
	}
	for (auto [u, v]: AC){
		ans -= 1LL*v*(v-1)/2;
	}
	for (auto [u, v]: ABC){
		ans += 2LL*v*(v-1)/2;
	}
	cout << ans << endl;
	
	return 0;
}


