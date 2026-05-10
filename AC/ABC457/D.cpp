#include <bits/stdc++.h>
using namespace std;
const long long INF = 4e18;
int n;
long long a[200005], k;

bool check(long long cap){
	long long cnt = 0;
	for (int i = 1; i <= n; i++){
		if (a[i] >= cap) continue;
		cnt += (cap-a[i]+i-1)/i;
		if (cnt > k) return 0;
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	// first one that doesnt work
	long long l = 1, r = INF;
	while (l < r){
		long long mid = (l+r)>>1;
		if (!check(mid)) r = mid;
		else l = mid+1;
	}
	cout << l-1 << endl;
	return 0;
}