#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const double EPS = 1e-2;
int q, n;
int lo[505], hi[505];
complex<double> d[1100005];
int k[500005][20];
int lg[500005];
int a[500005];

void FFT(complex<double> *a, int n, int inv){
	if (n == 1) return;
	int mid = n/2;
	complex<double> A1[mid];
	complex<double> A2[mid];
	for (int i = 0; i < n; i+=2){
		A1[i>>1] = a[i];
		A2[i>>1] = a[i+1];
	}
	FFT(A1, mid, inv);
	FFT(A2, mid, inv);
	complex<double> w(1, 0);
	complex<double> wn(cos(2*pi/n), sin(2*pi/n)*inv);
	for (int i = 0; i < mid; i++, w *= wn){
		a[i] = A1[i] + w * A2[i];
		a[i+n/2] = A1[i] - w * A2[i];
	}
}

int main(){
	lg[0] = -1;
	for (int i = 1; i <= 500000; i++){
		lg[i] = lg[i/2]+1; 
	}
	cin >> q;
	int mx = 0;
	for (int i = 1; i <= q; i++){
		cin >> lo[i] >> hi[i];
		mx = max(mx, hi[i]);
	}
	for (int i = 1; i <= mx; i++){
		for (int j = i; j <= mx; j+=i){
			d[j].real(d[j].real()+1);
		}
	}
	int len = 1<<max((int)ceil(log2(mx+mx+1)), 1);
	FFT(d, len, 1);
	for (int i = 0; i < len; i++){
		d[i] = d[i] * d[i];
	}
	FFT(d, len, -1);
	for (int i = 0; i <= mx; i++){
		a[i+1] = (int)(d[i].real() / len + EPS);
		k[i+1][0] = i+1;
	}
	mx++;
	for (int i = 1; i < 20; i++){
		for (int j = 1; j+(1<<i)-1 <= mx; j++){
			int x = k[j][i-1];
			int y = k[j+(1<<(i-1))][i-1];
			if (a[x] < a[y]){
				k[j][i] = y;
			} else {
				k[j][i] = x;
			}
		}
	}
	for (int i = 1; i <= q; i++){
		int l = lo[i]+1;
		int r = hi[i]+1;
		int len = lg[r-l+1];
		int x = k[l][len];
		int y = k[r-(1<<len)+1][len];
		int ans = (a[x]<a[y])?y:x;
		cout << ans-1 << ' ' << a[ans] << '\n';
	}

	return 0;
}

