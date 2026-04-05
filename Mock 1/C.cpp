#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
int n;
long long a[100005];
long long psum[100005];

int main(){
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
	cin >> n;
	long long maxx = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++){
		psum[i] = a[i]+psum[i-1];
	}
	// T1
	if (n <= 10){
		// brute force before 10^6
		int lim = 1000000;
		long long ans = INF;
		for (int d = 2; d <= lim; d++){
			long long tally = 0;
			long long curr = 1;
			for (int i = 1; i <= n; i++){
				while (curr < a[i] && (abs(curr * d - a[i]) <= a[i] - curr)){
					curr *= d;
				}
				tally += abs(a[i]-curr);
			}
			ans = min(ans, tally);
		}
		for (int cut = 0; cut <= n; cut++){
			// values: 1 to cut, cut + 1 to n
			// 1 portion:
			long long tally = psum[cut]-cut;
			long long d = (cut+1+n)/2;
			// consider d:
			long long a1 = (d-cut)*a[d]-(psum[d]-psum[cut]);
			a1 += ((psum[n]-psum[d])-(n-d)*a[d]);
			// consider d+1
			long long a2 = (d+1-cut)*a[d+1]-(psum[d+1]-psum[cut]);
			a2 += ((psum[n]-psum[d+1])-(n-d-1)*a[d+1]);
			tally += min(a1, a2);
			ans = min(ans, tally);
		}
		cout << ans << '\n';
	}

	// T2: ai <= 500
	else if (maxx <= 500){
		long long ans = INF;
		for (int d = 2; d <= 500; d++){
			long long tally = 0;
			long long curr = 1;
			for (int i = 1; i <= n; i++){
				while (curr < a[i] && (abs(curr * d - a[i]) <= a[i] - curr)){
					curr *= d;
				}
				tally += abs(a[i]-curr);
			}
			ans = min(ans, tally);
		}
		cout << ans << '\n';
	}

	// T3: ai <= n; if (maxx <= n)
	else {
		long long ans = INF;
		for (int d = 2; d <= 1000; d++){
			long long tally = 0;
			long long curr = 1;
			for (int i = 1; i <= n; i++){
				while (curr < a[i] && (abs(curr * d - a[i]) <= a[i] - curr)){
					curr *= d;
				}
				tally += abs(a[i]-curr);
			}
			ans = min(ans, tally);
		}
		// square would be over
		for (int cut = 0; cut <= n; cut++){
			// values: 1 to cut, cut + 1 to n
			// 1 portion:
			long long tally = psum[cut]-cut;
			long long d = (cut+1+n)/2;
			// consider d:
			long long a1 = (d-cut)*a[d]-(psum[d]-psum[cut]);
			a1 += ((psum[n]-psum[d])-(n-d)*a[d]);
			// consider d+1
			long long a2 = (d+1-cut)*a[d+1]-(psum[d+1]-psum[cut]);
			a2 += ((psum[n]-psum[d+1])-(n-d-1)*a[d+1]);
			tally += min(a1, a2);
			ans = min(ans, tally);
		}
		cout << ans << '\n';
	}

	return 0;
}










