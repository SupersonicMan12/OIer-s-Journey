#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[405];
int c[405];
// vector<pair<int,int>> V;

void printxy(int x, int y){
	cout << x << ' ' << y << '\n';
	// V.push_back({x,y});
}

void ts1(){
	if (n == 1) printxy(1, 1);
	if (n == 2){
		if (k == 1){
			printxy(1, 1);
			printxy(1, 2);
		} else {
			printxy(1, 1);
			printxy(2, 2);
		}
	} 
	if (n == 3) {
		if (k == 0){
			printxy(1,1);printxy(2,2);printxy(3,3);
		} else if (k == 1){
			printxy(1,1);printxy(2,2);printxy(2,3);
		} else if (k == 2){
			printxy(1,1);printxy(1,2);printxy(2,2);
		} else {
			printxy(1,2);printxy(1,1);printxy(1,3);
		}
	}
	if (n == 4) {
		if (k == 0){
			printxy(1,1);printxy(2,2);printxy(3,3);printxy(4,4);
		} else if (k == 1){
			printxy(1,1);printxy(2,2);printxy(3,3);printxy(4,3);
		} else if (k == 2){
			printxy(1,1);printxy(3,2);printxy(3,3);printxy(4,3);
		} else if (k == 3){
			printxy(1,1);printxy(1,3);printxy(1,5);printxy(2,2);
		} else if (k == 4){
			printxy(1,1);printxy(1,3);printxy(1,5);printxy(2,5);
		} else if (k == 5){
			printxy(1,1);printxy(1,3);printxy(1,7);printxy(5,4);
		} else {
			printxy(1,1);printxy(1,2);printxy(1,3);printxy(1,4);
		}
	}
}

void ts2(){
	for (int i = 1; i <= n; i++){
		printxy(1,i);
	}
}

void ts3(){
	for (int i = 1; i <= n; i++){
		printxy(i,i);
	}
}

void printdxy(int x, int y){
	cout << x*2 << ' ' << y*2 << '\n';
	// V.push_back({x*2,y*2});
}

int pow(int x, int n){
	int ans = 1;
	for (int i = 1; i <= n; i++) ans = ans*x;
	return ans;
}

// void self_check(){
// 	int cnt = 0;
// 	for (auto v : V){
// 		for (auto u : V){
// 			if (v.first == u.first && v.second == u.second) continue;			
// 			long long D = 1LL*(v.first-u.first)*(v.first-u.first)+1LL*(v.second-u.second)*(v.second-u.second);
// 			long long sq = sqrt(D);
// 			if (D == sq*sq) cnt++;
// 		}
// 	}
// 	cout << cnt/2 << '\n';
// }

void full(){
	int x=1;
	while (k <= (n-1)*(n-2)/2) {
		n--;
		printxy(x,x); x+=2;
	}
	if (k==(n)*(n-1)/2){
		for (int i = 1; i <= n; i++)
		printdxy(1,i);
		return;
	}
	int BIG = pow(2,12)*pow(3,4)*pow(5,4);
	int b = pow(2,6)*pow(3,2)*pow(5,2);
	int cnt = 0;
	for (int i = 1; i <= 10; i++){
		for (int j = 0; j <= 4; j++){
			for (int k = 0; k <= 4; k++){
				int x = pow(2,i)*pow(3,j)*pow(5,k);
				int y = BIG/x;
				if (x >= y) continue;
				a[++cnt] = (y-x)/2;
				c[cnt] = (x+y)/2;
			}
		}
	}
	// cout << cnt << '\n';
	int diff = (k-(n-1)*(n-2)/2-1);
	// diff points needed, diff <= n-2;
	printdxy(0,0);
	printdxy(b,0);
	for (int i = 1; i <= diff; i++){
		printdxy(0,a[i]);
	}
	for (int i = diff+1; i <= n-2; i++){
		printdxy(0,a[i]+1);
	}
	// self_check();
}

int main(){
	cin >> n >> k;
	if (n <= 4){
		ts1();
	} else if (k == n*(n-1)/2){
		ts2();
	} else if (k == 0){
		ts3(); 
	} else {
		full();
	}
	return 0;
}


