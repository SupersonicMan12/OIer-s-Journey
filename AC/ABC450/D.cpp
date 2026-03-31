#include <bits/stdc++.h>
using namespace std;

int n, K;
int a[200005];

int main(){
	cin >> n >> K;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] %= K;
	}
	sort(a+1, a+n+1);
	int large = a[1]+K-a[n];
	for (int i = 1; i < n; i++){
		large = max(large, a[i+1]-a[i]);
	}
	cout << K-large << '\n';
	return 0;
}