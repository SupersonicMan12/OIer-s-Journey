#include <bits/stdc++.h>
using namespace std;

int t, n;
struct nd{
	int x,y,z;
	bool operator<(const nd& other) const{
		if (y==other.y && x==other.x) return z>other.z;
		else if (x==other.x) return y>other.y;
		return x>other.x;
	}
} A[200005];
int untilx[200005];
int untily[200005];
int untilz[200005];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> A[i].x >> A[i].y >> A[i].z;
		untilx[A[i].x]++;
		untily[A[i].y]++;
		untilz[A[i].z]++;
	}
	int wx=200001,wy=200001,wz=200001;
	for (int i = n-1; i >= 1; i--){
		untilx[i] += untilx[i+1];
		untily[i] += untily[i+1];
		untilz[i] += untilz[i+1];
	}
	sort(A+1, A+n+1);
	for (int i = 1; i <= n; i++){
		wx = min(wx, A[i].x);
		wy = min(wy, A[i].y);
		wz = min(wz, A[i].z);
		if (untilx[wx] == i && untily[wy] == i && untilz[wz] == i){
			cout << i << '\n';
			break;
		} 
	}
	for (int i = 1; i <= n; i++){
		untilx[i]=untily[i]=untilz[i]=0;
	}
}

int main(){
	cin >> t; while (t--) solve();
	return 0;
}

