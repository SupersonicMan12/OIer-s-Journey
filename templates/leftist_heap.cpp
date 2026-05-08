#include <bits/stdc++.h>
using namespace std;

const int MAXH = 1000005;

struct LeftistHeap {
    struct Node{
        int l, r, dist, id;
    };
    static Node t[MAXN*2];
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
};

LeftistHeap::Node LeftistHeap::t[2*N];
LeftistHeap::tot = 0;


