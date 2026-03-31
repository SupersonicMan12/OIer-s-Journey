#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int lc[100005], rc[100005];
int stk[100005];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int top = 0;
	for (int i = 1; i <= n; i++){
		bool mark = 0;
		while (top > 0 && a[i] > a[stk[top]]) {top--; mark = 1;}
		if (top) rs[stk[top]] = i;
		if (mark) ls[i] = stk[top+1];
		stk[++top] = i;
	}
	
	return 0;
}