#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n;
int s[300005],t[300005];
struct node{
    int x, y, id;
} task[300005];
int ans[300005];
bool cmp(node a, node b){
    if (a.y == b.y) return a.x > b.x;
    return a.y < b.y;
}
multiset<pii> wag;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t[i] >> s[i];
        task[i] = {s[i]-t[i],s[i]+t[i], i};
    }
    sort(task+1, task+1+n, cmp);
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        auto it = wag.lower_bound({task[i].x, 0});
        if (it == wag.end()){
            wag.insert({task[i].x, ++cnt});
            ans[task[i].id] = cnt;
        } else {
            int wn = (*it).second;
            wag.erase(it);
            wag.insert({task[i].x, wn});
            ans[task[i].id] = wn;
        }
    }

    cout << wag.size() << '\n';
    
    return 0;
}