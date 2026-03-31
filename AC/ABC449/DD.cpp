#include <bits/stdc++.h>
using namespace std;

int intst(int L,int R,int l,int r){
    return max(0, min(R,r) - max(L,l) + 1);
}

long long F(int k,int l,int r,int d,int u){
	if (k == -1) return 0;
    int cx = intst(l,r,-k,k);
    int cy = intst(d,u,-k,k);
    return 1LL * cx * cy;
}

int main(){
    int l,r,d,u;
    cin >> l >> r >> d >> u;
    int K = max({abs(l), abs(r), abs(d), abs(u)});
    long long ans = 0;

    // onion peels
    for (int k = 0; k <= K; k += 2){
        ans += F(k,l,r,d,u) - F(k-1,l,r,d,u);
    }

    cout << ans << "\n";
}