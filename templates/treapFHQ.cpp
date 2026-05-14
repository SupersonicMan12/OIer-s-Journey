#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node{
	int l,r,sz;
	unsigned pri;
	int val;
} t[N];

int root, tot;

int sz(int x){
	return x?t[x].sz:0;
}

int newnode(int v){
	int x = ++tot;
	t[x].l = t[x].r = 0;
	t[x].sz = 1;
	t[x].pri = rng();
	t[x].val = v;
	return x;
}

void pull(int x){
	t[x].sz = sz(t[x].l)+sz(t[x].r)+1;
}

int merge(int a, int b){
	if (!a || !b) return a|b;
	if (t[a].pri < t[b].pri){
		t[a].r = merge(t[a].r, b);
		pull(a); return a;
	} else {
		t[b].l = merge(t[b].l, a);
		pull(b); return b;
	}
}

void split(int x, int k, int &a, int &b){
	if (!x){
		a=b=0; 
		return;
	}
	if (sz(t[x].l) >= k){
		split(t[x].l, k, a, t[x].l);
		pull(b = x);
	} else {
		split(t[x].r, k-sz(t[x].l)-1,t[x].r,b);
		pull(a = x);
	}
}

void insert(int pos, int val){
	int a, b; 
	split(root, pos, a, b);
	root = merge(merge(a, newnode(val)), b);
}

void erase(int pos){
	int a,b,c;
	split(root, pos, a, c);
	split(a, pos-1, a, b);
	root = merge(a, c);
}

void dfs(int x){
	if (!x) return;
	dfs(t[x].l);
	cout << t[x].val << ' ';
	dfs(t[x].r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i <= 4; i++){
    	insert(i-1, i);
    }
    dfs(root);
	cout << '\n';
    erase(2);
    dfs(root);
    cout << '\n';
    return 0;
}






