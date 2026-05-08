#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const long long INF = 1e18;
vector<int> G[N];
int n;
// minimum entry, return of minimum entry
long long f[N], g[N], profit[N], s;

// maintains smallest f
struct Leftist {
    struct Node{
        int l, r, dist;
        int id;
    };
    static Node t[N*2];
    static int tot;
    int root = 0, siz = 0;
    static bool better(int a, int b){
        if (f[t[a].id] != f[t[b].id]) return f[t[a].id] < f[t[b].id];
        return t[a].id < t[b].id;
    }
    static int new_node(int id){
        t[++tot] = {0,0,1,id};
        return tot;
    }
    static int meld(int a, int b){
        if (!a || !b) return a | b;
        // b < a, attach b to a
        if (!better(a, b)) swap(a, b);
        t[a].r = meld(t[a].r, b);
        // signature leftist:
        if (t[t[a].l].dist < t[t[a].r].dist){
            swap(t[a].l, t[a].r);
        }
        t[a].dist = t[t[a].r].dist + 1;
        return a;
    }
    void insert(int id){
        root = meld(root, new_node(id));
        siz++;
    }
    int size(){
        return siz;
    }
    bool empty(){
        return siz == 0;
    }
    int top(){
        return t[root].id;
    }
    void pop(){
        root = meld(t[root].l, t[root].r);
        siz--;
    }
    void merge(Leftist &other){
        root = meld(root, other.root);
        siz += other.siz;
        other.root = other.siz = 0;
    }
} branches[N];

Leftist::Node Leftist::t[N*2];
int Leftist::tot = 0;

void dfs(int x, int fa){
	g[x] = profit[x];
	f[x] = max(-profit[x], 0LL);
	for (int v : G[x]){
		if (v == fa) continue;
		dfs(v, x);
		if (f[v] != INF)
		branches[x].insert(v);
	}
	while (g[x] <= 0 && branches[x].size() > 0){
		int c = branches[x].top();
		branches[x].pop();
		f[x] = max(f[x], f[c]-g[x]); 
		g[x] += g[c];
		branches[x].merge(branches[c]);
	}
	if (g[x] <= 0) f[x] = INF;
}

long long finish(int x){
	Leftist L;
	long long bal = s;
	L.insert(x);
	while (!L.empty()){
		int u = L.top(); L.pop();
		if (bal < f[u]) break;
		bal += g[u];
		L.merge(branches[u]);
	}
	return bal-s;
}

int main(){
	cin >> n >> s;
	for (int i = 1; i <= n; i++){
		int p; cin >> profit[i] >> p;
		G[p].push_back(i);
	}
	dfs(0,0);
	cout << finish(0) << endl;
}

