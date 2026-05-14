#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
long long ANS = 0;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node{
	int l,r,sz;
	unsigned pri;
	int val, lz;
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
	t[x].lz = 0;
	return x;
}

void push(int x){
	if (!x || !t[x].lz) return;
	if (t[x].l){
		t[t[x].l].lz += t[x].lz;
		t[t[x].l].val += t[x].lz;
	}
	if (t[x].r){
		t[t[x].r].lz += t[x].lz;
		t[t[x].r].val += t[x].lz;
	}	
	t[x].lz = 0;
}

void pull(int x){
	t[x].sz = sz(t[x].l)+sz(t[x].r)+1;
}

int merge(int a, int b){
	if (!a || !b) return a|b;
	if (t[a].pri < t[b].pri){
		push(a);
		t[a].r = merge(t[a].r, b);
		pull(a); 
		return a;
	} else {
		push(b);
		t[b].l = merge(a, t[b].l); //!!
		pull(b); 
		return b;
	}
}

void split(int x, int k, int &a, int &b){
	if (!x){
		a=b=0; 
		return;
	}
	push(x);
	if (k <= sz(t[x].l)){
		split(t[x].l, k, a, t[x].l);
		pull(b = x);
	} else {
		split(t[x].r, k-sz(t[x].l)-1,t[x].r,b);
		pull(a = x);
	}
}

void split_val(int x, int v, int &a, int &b){
	if (!x) {
		a=b=0;
		return;
	}
	push(x);
	if (v < t[x].val){
		split_val(t[x].l, v, a, t[x].l);
		pull(b = x);
	} else {
		split_val(t[x].r, v, t[x].r, b);
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

void push_all(int x){
	if (!x) return;
	push(x);
	int res = t[x].val;
	// cout << res << '\n';
	ANS += 1LL*(res)*(res-1)/2;
	push_all(t[x].l);
	push_all(t[x].r);
}

int Max(int x){
	while (1){
		push(x);
		if (!t[x].r) break;
		x = t[x].r;
	}
	return t[x].val;
}

int n;
pair<int,int> P[100005];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> P[i].first >> P[i].second;
	}
	sort(P+1, P+1+n);
	for (int i = 1; i <= n; i++){
		int h = P[i].first, k = P[i].second; 
		int prevh = P[i-1].first;
		// append(h-prevh, 0);
		for (int j = 1; j <= h-prevh; j++) insert(0, 0);
		// 0 0 0 1 1 2 2 2 2 3
		// 1 1 1 2 2 3 3 2 2 3
		int x, y, z;
		split(root, k, x, y); t[x].val++; t[x].lz++;
		int mx = Max(x);
		split_val(x, mx-1, x, z); x = merge(x, y);
		split_val(x, mx, x, y);
		root =  merge(merge(x,z),y);
		// dfs(root); cout << endl;
	}
	push_all(root);
	cout << ANS << '\n';
    return 0;
}






