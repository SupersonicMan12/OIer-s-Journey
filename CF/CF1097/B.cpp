#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct Mint {
    int v;
    Mint(long long x = 0) : v((x % MOD + MOD) % MOD) {}
    Mint operator+(Mint o) { return Mint(v + o.v >= MOD ? v + o.v - MOD : v + o.v, 0); }
    Mint operator-(Mint o) { return Mint(v - o.v < 0 ? v - o.v + MOD : v - o.v, 0); }
    Mint operator*(Mint o) { return Mint(1LL * v * o.v % MOD, 0); }
    Mint operator/(Mint o) { return *this * o.pw(MOD - 2); }
    Mint& operator+=(Mint o) { return *this = *this + o; }
    Mint& operator-=(Mint o) { return *this = *this - o; }
    Mint& operator*=(Mint o) { return *this = *this * o; }
    Mint& operator/=(Mint o) { return *this = *this / o; }
    Mint pw(long long e) { Mint r(1, 0), b = *this; for (; e; e >>= 1, b = b * b) if (e & 1) r = r * b; return r; }
    friend ostream& operator<<(ostream& s, Mint m) { return s << m.v; }
    friend istream& operator>>(istream& s, Mint& m) { long long x; s >> x; m = x; return s; }
private:
    Mint(int x, int) : v(x) {}
};

struct Frac{
	long long p, q;
	bool operator<(const Frac& other) const{
		return p*other.q < q*other.p;
	}
} tmp[4000005];

int n, cnt;
int a[2005], b[2005];

void solve(){
	cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i != j)
			tmp[++cnt] = {b[j], b[i]};
		}
	}
	sort(tmp+1, tmp+cnt+1);
	Mint ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			int u = lower_bound(tmp+1, tmp+cnt+1, (Frac){a[i], a[j]})-tmp-1;
			ans += ((Mint)(u))/((Mint)cnt);
		}
	}
	cout << ans << '\n';
}

int main(){
	int T; cin >> T;
	while (T--){
		solve();
	}
	return 0;
}