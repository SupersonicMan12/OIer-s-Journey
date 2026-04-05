#include <bits/stdc++.h>
using namespace std;

int h, w;

int main(){
	cin >> h >> w;
	for (int i = 1; i <= w; i++){
		cout << "#";
	}
	cout << '\n';
	for (int i = 2; i < h; i++){
		cout << "#";
		for (int j = 2; j < w; j++){
			cout << ".";
		}
		cout << "#\n";
	}
	for (int i = 1; i <= w; i++){
		cout << "#";
	}
	cout << '\n';
	return 0; 
}