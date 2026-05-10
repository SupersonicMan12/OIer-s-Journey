#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
int x;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> x;
	cout << a[x] << endl;
	return 0;
}