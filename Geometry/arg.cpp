#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> P[200005];

int q(int i){
    int x = 
    if ()
}

bool cmp(int i, int j){
    int q1 = q(i), q2 = q(j);
    if (q1 != q2) return q1 < q2;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> P[i].first >> P[i].second;
    }
    sort(P+1,P+n+1, cmp);

    return 0;
}