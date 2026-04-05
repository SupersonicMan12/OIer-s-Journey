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



