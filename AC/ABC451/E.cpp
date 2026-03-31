#include <bits/stdc++.h>
using namespace std;

int n;
int a[3005][3005];
struct S{
    int d, xx, yy;
    bool operator<(const S& other) const {
        if (d != other.d) return d < other.d;
        if (xx != other.xx) return xx < other.xx;
        return yy < other.yy;
    }
};
set<S> business;
int fa[3005];
int find(int x){
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}
vector<pair<int,int>> G[3005];
int dp[3005][3005];

void dfs(int rt, int x, int f){
    for (auto [v, w]: G[x]){
        if (v == f) continue;
        dp[rt][v] = dp[rt][x] + w;
        dfs(rt, v, x);
    }   
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            cin >> a[i][j];
            business.insert(S{a[i][j],i,j});
        }
    }
    auto it = business.begin();
    for (int i = 1; i < n; i++){
        int dist = (*it).d, x = (*it).xx, y = (*it).yy;
        while (find(x)==find(y)){
            it++;
            dist = (*it).d, x = (*it).xx, y = (*it).yy;
        }
        G[x].push_back({y,dist});
        G[y].push_back({x,dist});
        x = find(x), y = find(y);
        fa[x] = y;
    }
    for (int i = 1; i <= n; i++) dfs(i, i, 0);
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if (dp[i][j] != a[i][j]) {
                cout << "No\n"; 
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}


