#include <bits/stdc++.h>
using namespace std;

int n; long long k;
int t[500005];
int a[500005];
void insert(int x){
	for (;x<=n;x+=(x&(-x))){
		t[x]++;
	}
}
void remove(int x){
	for (;x<=n;x+=(x&(-x))){
		t[x]--;
	}
}
int qry(int x){
	int s = 0;
	for (;x;x-=(x&(-x))){
		s += t[x];
	}
	return s;
}

//counts those <= k
long long solve(long long k){
	if (k < 0) return 0;
	memset(t, 0, sizeof(t));
	int l = 1;
	long long ans = 0;
	long long cnt = 0;
	for (int i = 1; i <= n; i++){
		while (l <= n){
			int q = qry(n)-qry(a[l]);
			if (cnt+q > k) break;
			insert(a[l++]);
			cnt += q;
		}
		ans += (l-i);
		cnt -= qry(a[i]-1);
		remove(a[i]);
	}
	return ans;
}

int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << solve(k)-solve(k-1) << endl;
	return 0;
}












