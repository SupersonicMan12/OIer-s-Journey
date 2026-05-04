#include <bits/stdc++.h>
using namespace std;

int a[4][7];

int main(){
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 6; j++){
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 6; i++){
		for (int j = 1; j <= 6; j++){
			for (int k = 1; k <= 6; k++){
				vector<int> V;
				V.push_back(a[1][i]);
				V.push_back(a[2][j]);
				V.push_back(a[3][k]);
				sort(V.begin(), V.end());
				if (V[0]==4 && V[1]==5 && V[2]==6){
					cnt++;
				}
			}
		}
	}
	cout << fixed << setprecision(10) << 1.0*cnt/216 << endl;
	return 0;
}