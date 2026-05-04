#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e17;
int n, k;
int a[200005];
struct Mat{
	long long mat[2][2];
} t[800005];


Mat merge(Mat y, Mat z){
	Mat x;
	x.mat[0][0] = min(y.mat[0][0]+z.mat[1][0], min(y.mat[0][1]+z.mat[0][0], y.mat[0][1]+z.mat[1][0]));
	x.mat[0][1] = min(y.mat[0][0]+z.mat[1][1], min(y.mat[0][1]+z.mat[0][1], y.mat[0][1]+z.mat[1][1]));
	x.mat[1][0] = min(y.mat[1][0]+z.mat[1][0], min(y.mat[1][1]+z.mat[0][0], y.mat[1][1]+z.mat[1][0]));
	x.mat[1][1] = min(y.mat[1][0]+z.mat[1][1], min(y.mat[1][1]+z.mat[0][1], y.mat[1][1]+z.mat[1][1]));
	if (x.mat[0][0]>INF) x.mat[0][0] = INF;
	if (x.mat[0][1]>INF) x.mat[0][1] = INF;
	if (x.mat[1][0]>INF) x.mat[1][0] = INF;
	if (x.mat[1][1]>INF) x.mat[1][1] = INF;
	return x;
}

void build(int x, int l, int r){
	if (l == r){
		t[x].mat[0][1] = t[x].mat[1][0] = INF;
		t[x].mat[0][0] = 0;
		t[x].mat[1][1] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	t[x] = merge(t[x<<1], t[x<<1|1]);
}

Mat qry(int x, int l, int r, int ql, int qr){
	Mat ans; ans.mat[0][0] = -1;
	if (ql <= l && qr >= r) return t[x];
	int mid = (l+r)>>1;
	if (ql <= mid) {
		ans = qry(x<<1, l, mid, ql, qr);
	}
	if (qr > mid){
		Mat ret = qry(x<<1|1, mid+1, r, ql, qr);
		if (ans.mat[0][0]==-1) {
			ans = ret;
		} else {
			ans = merge(ans, ret);
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	while (T--){
		cin >> n >> k;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		build(1, 1, n);
		long long ans = INF;
		for (int l = 1; l <= n; l++){
			int r1 = l+k-1;
			int r2 = l+k+1-1;
			if (r1 <= n){
				Mat ret = qry(1,1,n,l,r1);
				ans = min(ans, ret.mat[1][1]);
			} 
			if (r2 <= n){
				Mat ret = qry(1,1,n,l,r2);
				ans = min(ans, ret.mat[1][1]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}






