/*
1 2 4 8 16 32 64 128 256 512 1024
12 14 18 21 22 24 28 
*/

#include <bits/stdc++.h>
using namespace std;
const int cap = 1e9;
vector<string> alpha;
set<int> res;

// building list complete
void dfs(int curr, int len) {
    if (curr > 0) res.insert(curr);
    for (string s : alpha) {
        int nlen = len + s.size();
        if (nlen > 9) continue;
        // build new number
        // by adding to back.
        int nxt = curr;
        for (char c : s) nxt = nxt * 10 + (c - '0');
        if (nxt > cap) continue;
        dfs(nxt, nlen);
    }
}

int main() {
    long long v = 1;
    while (v < cap) {
        alpha.push_back(to_string(v));
        v <<= 1;
    }
    dfs(0, 0);
    vector<long long> ans(res.begin(), res.end());
    int q; cin >> q;
    cout << ans[q - 1] << '\n';
}


