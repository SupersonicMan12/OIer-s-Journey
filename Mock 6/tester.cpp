#include <bits/stdc++.h>
using namespace std;

bool prime[105];

int main(){
	for (int i = 2; i <= 100; i++) prime[i] = 1;
	for (int i = 2; i <= 100; i++){
		if (prime[i]){
			for (int j = 2*i; j <= 100; j += i){
				prime[j] = 0;
			}
			cout << i << ',';
		}
	}


	return 0;
}