// Sketch: BIT with walk for sum of smallest K
struct BIT {
    int n;
    vector<long long> cnt, val; // count tree, value-sum tree
    BIT(int n): n(n), cnt(n+1), val(n+1) {}
    void update(int i, int dc, int dv) {
        for (; i <= n; i += i&-i) cnt[i] += dc, val[i] += dv;
    }
    // Returns sum of smallest k elements
    long long ksmallest(int k) {
        int pos = 0;
        long long res = 0;
        for (int pw = __lg(n); pw >= 0; pw--) {
            int nxt = pos + (1 << pw);
            if (nxt <= n && cnt[nxt] <= k) {
                k -= cnt[nxt];
                res += val[nxt];
                pos = nxt;
            }
        }
        return res;
    }
};
