#include <bits/stdc++.h>
using namespace std;

int n;
int a[2003][2003];
int S, C;
bool ans[2005];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			cin >> a[i][j];
		}
	}
	S = a[1][n];
	int l = 1, r = n;
	while (a[l][n]==S) l++;
	while (a[1][r]==S) r--;
	l--; r++; 
	ans[l] = ans[r] = 1;
	// consider interval l, r with endpoints B
	int c = 1;
	for (int i = l+1; i < r; i++){
		// B dominates [l, i)
		if (a[l][i-1]==c && a[l+1][i-1]==c-1){
			if (a[l][i-1] != a[l][i]){
				ans[i] = 1; 
				c++;
			}
		}
		// B dominates [i, r]
		else if (a[i][r]==S-c && a[i][r-1]==S-c-1){
			if (a[i][r] != a[i+1][r]){
				ans[i] = 1;
				c++;
			}
		}
		// B dominates neither, 
		else {
			if (a[l+1][i]==a[l+1][i-1] && a[i][r-1]==a[i+1][r-1]){
				ans[i] = 1;
				c++;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		if (ans[i]) cout << i << ' ';
	}
	cout << endl;

	return 0;
}



