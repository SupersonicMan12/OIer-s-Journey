/*

Find largest sum of contiguous elements of length at most M, given seq N

N, M <= 1e6.

We want max(i from 1 to n) max(1 <= j < i, i-j <= m) (si-sj)

We want the smallest sj. Consider sequence <j, sj>

If si > sj & i < j, this si is useless. 

Hence maintain <j, sj> of both elements increasing. 

New element eliminates large sj from head
Each move in i leads to elimination in tail

*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
int s[1000006];
int q[1000006];
int ans = -2e9; 

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s[i]; s[i] += s[i-1];
	}
	int head = 1, tail = 1;
	for (int i = 1; i <= n; i++){
		ans = max(ans, s[i]-s[q[tail]]);
		while (head>=tail && s[q[head]]>=s[i]){
			head--;
		}
		q[++head] = i;
		// expires next turn
		if (q[tail] == i-m) tail++; 
	}
	cout << ans << '\n';
}



