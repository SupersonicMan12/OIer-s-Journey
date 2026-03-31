#include <bits/stdc++.h>
using namespace std;

int n;
int co[105][105];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			cin >> co[i][j];
		}
	}
	for (int a = 1; a <= n; a++){
		for (int b = a+1; b <= n; b++){
			for (int c = b+1; c <= n; c++){
				if (co[a][b]+co[b][c]<co[a][c]){
					cout << "Yes\n";
					return 0;
				}
			}
		}
	}
	cout << "No\n";
	return 0;
}