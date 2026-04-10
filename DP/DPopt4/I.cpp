#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005], b[100005], w[100005];
multiset<ll> L, R;
ll tl = 0, tr = 0, ans = 0;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        w[i] = b[i]-a[i];
    }
    // the initial line = |x - a[1]|
    // L: transition between -1, 0 at first
    // R: transition between 0, 1 at first
    // L has all its values = actual - tl
    // R has all its values = actual + tr
    L.insert(a[1]);
    R.insert(a[1]);
    for (int i = 2; i <= n; i++) {
        tl += w[i];
        tr += w[i-1];
        // global minimum segment at [nl-tl, nr+tr]
        ll l = *L.rbegin();
        ll r = *R.begin();
        // left part
        if (l - tl > a[i]) {
            ans += abs(l - tl - a[i]);
            L.erase(--L.end());
            L.insert(a[i] + tl);
            L.insert(a[i] + tl);
            R.insert(l - tl - tr);
        } else if (a[i] > r + tr) { // right part
            ans += abs(r + tr - a[i]);
            R.erase(R.begin());
            R.insert(a[i] - tr);
            R.insert(a[i] - tr);
            L.insert(r + tr + tl);
        } else {
            L.insert(a[i] + tl);
            R.insert(a[i] - tr);
        }
    }
    
    cout << ans << endl;
    return 0;
}