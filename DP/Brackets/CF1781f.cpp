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

int n, q;
Mint dp[505][505], g[505][505];
Mint comb[505][505];

int main(){
    cin >> n >> q;
    Mint p = (Mint)q / (Mint)10000;

    for (int i = 0; i <= n; i++){
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++){
            comb[i][j] = comb[i-1][j]+comb[i-1][j-1];
        }
    }
    // base case:
    for (int i = 0; i <= n; i++){
        dp[0][i] = g[0][i] = 1;
    }
    // computing row dp[i][~] and g[i][~]
    for (int i = 1; i <= n; i++){
        for (int x = 0; x <= n-i; x++){
            for (int j = 0; j <= i-1; j++){
                Mint special = (x==0)?0:dp[j][x-1];
                dp[i][x] += ( p*dp[j][x+1] + ((Mint)1-p)* special) * comb[i-1][j] * g[i-1-j][x];
            }
        }
        for (int x = 0; x <= n-1; x++){
            for (int j = 0; j <= i; j++){
                g[i][x] += comb[i][j] * dp[j][x] * dp[i-j][x]; 
            }
        }
    }
    for (int i = 1; i <= 2*n; i+=2){
        dp[n][0] /= i;
    }
    cout << dp[n][0] << '\n';
    
    return 0;
}







