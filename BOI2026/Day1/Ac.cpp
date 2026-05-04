#include <bits/stdc++.h>
using namespace std;

int a[200005], n, k, mid;
int cnt[200005];
int ans[200005];

void answer(){
	cout << "YES\n";
	for (int i = 1; i <= n; i++) 
		cout << ans[i] << ' ';
	cout << '\n';
}

void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) a[i] = 0;
	for (int i = 1; i <= k; i++) cnt[i] = 0;
	if (n % 2 == 0){
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			cnt[a[i]]++;
		}
		int curr = 1;
		for (int i = 1; i <= k; i++){
			if (cnt[i] % 2){
				cout << "NO\n";
				return;
			}
			while (cnt[i]>0){
				cnt[i]-=2;
				ans[curr] = ans[n+1-curr] = i;
				curr++;
			}
		}
		answer();
	} else {
		mid = (n+1)/2;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			cnt[a[i]]++;
		}
		int singles = 0, itis;
		int curr = 1, len = n;
		vector<int> V;
		for (int i = 1; i <= k; i++){
			if (cnt[i]==1){
				singles++;
				itis = i;
			} else if (cnt[i]%2){
				while (cnt[i]>3){
					cnt[i]-=2;
					ans[curr] = ans[n+1-curr] = i;
					curr++;
					len-=2;
				}
				// a triplet of i remains
				V.push_back(i);
			} else {
				while (cnt[i]>0){
					cnt[i]-=2;
					ans[curr] = ans[n+1-curr] = i;
					curr++;
					len-=2;
				}
			}
		}
		if (singles > 1){
			cout << "NO\n";
		} else {
			if (len % 6 == 3){
				ans[mid-len/2]=ans[mid+len/2]=ans[mid]=V.back();
				V.pop_back();
				len-=3;
			} else {
				ans[mid] = itis;
				len-=1;
			}
			int ccc = len/3;
			for (int color = 0; color < ccc/2; color++){
				int p1 = len/2-2*color;
				int p2 = (len/6-color);
				int p3 = (len/3-color);
				ans[mid-p1]=ans[mid+p2]=ans[mid+p3]=V[color];
			}
			for (int color = 0; color < ccc/2; color++){
				int p1 = color+1;
				int p2 = len/2-1-2*color;
				int p3 = len/2-color;
				ans[mid-p1]=ans[mid-p2]=ans[mid+p3]=V[color+ccc/2];
			}
			answer();
		} 
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while (T--) solve();

	return 0;
}


