#include <bits/stdc++.h>
using namespace std;

int n, a[400005], cnt;
int t[12100000][2];
int leftpart[400005];
int rightpart[400005];

int main(){
	cin >> n;
	a[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] ^= a[i-1]; 
	}
	// within 1<<30 
	// leftpart for l1 r1
	int x = 0;
	for (int bit = 1<<30; bit; bit >>= 1){
		t[x][0] = ++cnt; x = t[x][0];
	}
	for (int B = 1; B <= n; B++){
		// check B:
		x = 0;
		int ans = 0;
		for (int bit = 1<<30; bit; bit >>= 1){
			bool is = (a[B]&bit)>0;
			if (t[x][is^1]) {
				x = t[x][is^1];
				ans |= bit;
			} else x = t[x][is];
		}
		x = 0;
		leftpart[B] = max(leftpart[B-1], ans);
		for (int bit = 1<<30; bit; bit >>= 1){
			bool is = (a[B]&bit)>0;
			if (!t[x][is]) t[x][is] = ++cnt; 
			x = t[x][is];
		}
	}
	memset(t, 0, sizeof(t));
	cnt = 0;
	x = 0;
	for (int bit = 1<<30; bit; bit >>= 1){
		bool is = (a[n]&bit)>0;
		if (!t[x][is]) t[x][is] = ++cnt; 
		x = t[x][is];
	}
	rightpart[n] = 0;
	for (int B = n-1; B >= 1; B--){
		// check B:
		x = 0;
		int ans = 0;
		for (int bit = 1<<30; bit; bit >>= 1){
			bool is = (a[B]&bit)>0;
			if (t[x][is^1]) {
				x = t[x][is^1];
				ans |= bit;
			} else x = t[x][is];
		}
		x = 0;
		rightpart[B] = max(rightpart[B+1], ans);
		for (int bit = 1<<30; bit; bit >>= 1){
			bool is = (a[B]&bit)>0;
			if (!t[x][is]) t[x][is] = ++cnt; 
			x = t[x][is];
		}
	}
	int ans = 0;
	for (int B = 1; B <= n; B++){
		ans = max(ans, leftpart[B]+rightpart[B]);
	}
	cout << ans << '\n';

	return 0;
}
