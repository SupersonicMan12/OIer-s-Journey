#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int Q = 200005;
int n, m, q;
int freq[N];
pair<long long,int> qry[Q];
pair<int,int> train[N];
int a[N];
int ans[Q];

int t[N];
void add(int x, int v){
	for (;x<N;x+=x&(-x)){
		t[x] += v;
	}
}
int query(int x){
	int s = 0;
	for (;x>=1;x-=x&(-x)){
		 s += t[x];
	}
	return s;
}
int kth(int qt){
	// binary search on [1, l];
	int l = 1, r = m;
	while (l < r){
		int mid = (l+r)>>1;
		if (query(mid) < qt) l = mid+1;
		else r = mid;
	}
	return l;
}

int main(){
	cin >> n >> m;
	int mn = 700000;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		freq[a[i]]++;
	}
	for (int i = 1; i <= m; i++){
		train[i].first = freq[i];
		train[i].second = i;
		mn = min(mn, freq[i]);
	}
	train[0].first = mn;
	sort(train+1, train+1+m);

	cin >> q;
	for (int i = 1; i <= q; i++){
		cin >> qry[i].first;
		qry[i].second = i;
	}
	sort(qry+1, qry+q+1);
	// now traverse
	long long taken = n;
	int now = 1;

	for (int i = 1; i <= q; i++){
		long long x = qry[i].first;
		int idx = qry[i].second;
		if (x <= n) {
			ans[idx] = a[x];
			continue;
		}
		while (now <= m && x-taken > 1LL*(train[now].first-train[now-1].first)*query(m)){
			taken += 1LL*(train[now].first-train[now-1].first)*query(m);
			add(train[now].second, 1); now++;
		}
		int onbus = query(m);
		int rem = (x-taken)%onbus;
		if (rem == 0) rem = onbus;
		ans[idx] = kth(rem);
	}
	for (int i = 1; i <= q; i++){
		cout << ans[i] << '\n';
	}

	return 0;
}