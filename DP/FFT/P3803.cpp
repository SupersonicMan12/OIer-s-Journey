// from amazing post https://zhuanlan.zhihu.com/p/347091298

#include <bits/stdc++.h>
using namespace std;

const int N = (1<<22)+3;
const double eps = 1e-3, pi = acos(-1.0);
complex<double> a[N], b[N];
int n, m;
void FFT(complex<double> *a, int n, int inv){
	if (n == 1) return;
	int mid = n/2;
	complex<double> A1[mid+1], A2[mid+1];
	for (int i = 0; i < n; i+=2){
		A1[i/2] = a[i];
		A2[i/2] = a[i+1];
	}
	FFT(A1, mid, inv);
	FFT(A2, mid, inv);
	complex<double> w(1,0);
	complex<double> wn(cos(2*pi/n), inv*sin(2*pi/n));
	for (int i = 0; i < mid; i++, w *= wn){
		a[i]     = A1[i]+w*A2[i];
		a[i+n/2] = A1[i]-w*A2[i];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i <= n; i++){
		double x; cin >> x;
		a[i].real(x);
	}
	for (int i = 0; i <= m; i++){
		double x; cin >> x;
		b[i].real(x);
	}
	int len = 1<<max((int)ceil(log2(n+m+1)), 1);
	FFT(a, len, 1);
	FFT(b, len, 1);
	for (int i = 0; i < len; i++){
		a[i] = a[i]*b[i];
	}
	FFT(a, len, -1);
	for (int i = 0; i <= n+m; i++){
		cout << (int)(a[i].real() / len + eps) << ' ';
	}
	return 0;
}