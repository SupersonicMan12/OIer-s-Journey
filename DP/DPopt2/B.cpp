#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[50005];
pair<int,int> b[50005];
long long w[50005], h[50005];
long long dp[50005];
int Q[50005];

bool check(int i, int j, int k){
	return ((dp[i]-dp[j])*(w[j+1]-w[k+1]) <= (dp[j]-dp[k])*(w[i+1]-w[j+1]));
}

long long evaluate(int x, int i){
	return w[x+1] * h[i] + dp[x];
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a+1, a+n+1);
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		while (cnt > 0 && b[cnt].second <= a[i].second){
			cnt--;
		}
		b[++cnt] = a[i];
	}
	for (int i = 1; i <= cnt; i++){
		h[i] = b[i].first;
		w[i] = b[i].second; 
	}

	// dp[i] = MIN(dp[j] + w[j+1] * h[i])
	// force dp[j] as yinte and w[j+1] as slope, 
	// slope descends
	// start with dp[0] = 0, Q[1] = 0
	int head = 1, tail = 1;
	for (int i = 1; i <= cnt; i++){
		while (tail < head && evaluate(Q[tail], i) >= evaluate(Q[tail+1], i)){
			tail++;
		}
		dp[i] = evaluate(Q[tail], i);
		while (head - tail > 0 && check(Q[head-1], Q[head], i)){
			head--;
		}
		Q[++head] = i;
	}
	cout << dp[cnt] << '\n';

	return 0;
}