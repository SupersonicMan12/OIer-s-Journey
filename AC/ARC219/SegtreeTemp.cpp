#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 i128;
int n, q;
const int N = 200005;
const int MOD = 1e9+7;

ll a[N], tr[N << 2], mul[N << 2], add[N << 2];

ll norm(ll x){
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}

ll M(ll x, ll y){
    return (ll)((i128)x * y % MOD);
}

void pushup(int p){
    tr[p] = tr[p << 1] + tr[p << 1 | 1];
    if (tr[p] >= MOD) tr[p] -= MOD;
}

void apply(int p, int l, int r, ll m, ll b){
    tr[p] = (M(tr[p], m) + M(r - l + 1, b)) % MOD;
    mul[p] = M(mul[p], m);
    add[p] = (M(add[p], m) + b) % MOD;
}

void pushdown(int p, int l, int r){
    if (mul[p] == 1 && add[p] == 0) return;
    int mid = (l + r) >> 1;
    apply(p << 1, l, mid, mul[p], add[p]);
    apply(p << 1 | 1, mid + 1, r, mul[p], add[p]);
    mul[p] = 1;
    add[p] = 0;
}

void build(int p, int l, int r){
    mul[p] = 1;
    add[p] = 0;
    if (l == r){
        tr[p] = norm(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}

// range: a[i] = a[i] * m + b
void upd(int p, int l, int r, int ql, int qr, ll m, ll b){
    if (ql <= l && r <= qr){
        apply(p, l, r, norm(m), norm(b));
        return;
    }
    pushdown(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) upd(p << 1, l, mid, ql, qr, m, b);
    if (qr > mid) upd(p << 1 | 1, mid + 1, r, ql, qr, m, b);
    pushup(p);
}

ll qry(int p, int l, int r, int ql, int qr){
    if (ql <= l && r <= qr) return tr[p];
    pushdown(p, l, r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (ql <= mid) res = (res + qry(p << 1, l, mid, ql, qr)) % MOD;
    if (qr > mid) res = (res + qry(p << 1 | 1, mid + 1, r, ql, qr)) % MOD;
    return res;
}