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
		} else if (singles == 1){
			// n congruent to 1 mod 6
			if (len == 1){
				ans[mid] = itis;
				answer();
			} else if (len == 7){
				ans[mid-3]=ans[mid+1]=ans[mid+2]=V[0];
				ans[mid-2]=ans[mid-1]=ans[mid+3]=V[1];
				ans[mid]=itis;
				answer();
			} else if (len == 13){
				ans[mid-6]=ans[mid+2]=ans[mid+4]=V[0];
				ans[mid-5]=ans[mid-1]=ans[mid+6]=V[1];
				ans[mid-4]=ans[mid+1]=ans[mid+3]=V[2];
				ans[mid-3]=ans[mid-2]=ans[mid+5]=V[3];
				ans[mid]=itis;
				answer();
			} else if (len % 12 == 7){
				cout << "NO\n";
			}
		} else { // n congruent to 3 mod 6
			if (len == 3){
				ans[mid-1]=ans[mid]=ans[mid+1]=V[0];
				answer();
			} else if (len == 9){
				ans[mid-4]=ans[mid]=ans[mid+4]=V[0];
				ans[mid-3]=ans[mid+1]=ans[mid+2]=V[1];
				ans[mid-2]=ans[mid-1]=ans[mid+3]=V[2];
				answer();
			} else if (len % 12 == 3){
				int l = len/6;
				for (int i = 1; i <= l; i++){
					int links, rechts;
					if (i % 2){
						rechts = l+l+1+l/2-(i-1)/2;
						links = rechts+i;
					} else {
						rechts = l+l/2-(i-2)/2;
						links = rechts+i;
					}
					ans[mid+i] = ans[mid-links] = ans[mid+rechts] = V[(i-1)*2];
					ans[mid-i] = ans[mid+links] = ans[mid-rechts] = V[(i-1)*2+1];
				}
				int uniq = l+l/2+1;
				ans[mid-uniq]=ans[mid]=ans[mid+uniq]=V[2*l];
				answer();
			} else if (len % 12 == 9){
				int l = len/6;
				for (int i = 1; i <= l; i++){
					int links, rechts;
					if (i % 2){
						rechts = l+l/2+1+l-(i-1)/2;
						links = rechts+i;
					} else {
						rechts = l+l/2-(i-2)/2;
						links = rechts+i;
					}
					ans[mid+i] = ans[mid-links] = ans[mid+rechts] = V[(i-1)*2];
					ans[mid-i] = ans[mid+links] = ans[mid-rechts] = V[(i-1)*2+1];
				}
				int uniq = l+l/2+1;
				ans[mid-uniq]=ans[mid]=ans[mid+uniq]=V[2*l];
				answer();
			}
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


