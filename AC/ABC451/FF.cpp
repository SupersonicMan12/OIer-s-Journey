#include <bits/stdc++.h>
using namespace std;
int n, q, ans;
int fa[200005], rnk[200005];
int rel[200005];
int cnt[200005][2];

int find(int x) {
    if (fa[x] == x) return x;
    int r = find(fa[x]);
    rel[x] ^= rel[fa[x]];
    return fa[x] = r;
}

int main() {
    scanf("%d%d", &n, &q);
    ans = n;
    for (int i = 1; i <= n; i++) {
        fa[i] = i; 
        rnk[i] = 0;
        rel[i] = 0;
        // default white
        cnt[i][0] = 1;
        cnt[i][1] = 0;
    }
    bool flag = 0;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        if (flag) { 
            cout << -1 << '\n'; 
            continue; 
        }
        int fx = find(x), fy = find(y);
        if (fx == fy) {
            if (rel[x] == rel[y]) flag = 1;
            if (flag) { 
                cout << -1 << '\n'; 
                continue; 
            }
        } else {
            // old
            ans -= max(cnt[fx][0], cnt[fx][1]);
            ans -= max(cnt[fy][0], cnt[fy][1]);
            // this is parity of fy to fx, as we prep to attach fy under fx:
            int need = rel[x]^rel[y]^1;
            if (rnk[fx] < rnk[fy]) swap(fx, fy); 
            cnt[fx][need^0] += cnt[fy][0];
            cnt[fx][need^1] += cnt[fy][1];
            fa[fy] = fx;
            rel[fy] = need; // to fx
            if (rnk[fx] == rnk[fy]) rnk[fx]++;
            // otherwise fx wont change in height.
            ans += max(cnt[fx][0], cnt[fx][1]);
        }
        cout << n-ans << '\n';
    }
}