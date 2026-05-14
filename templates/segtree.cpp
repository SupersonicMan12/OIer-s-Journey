// maximum segment tree
struct node{
	int val, lc, rc, lz;
} t[6*N+9];
int cc;

void build(int &x, int l, int r){
	if (!x) x = ++c;
	if (l == r){
		t[x].val = d[V[l]];
		return;
	}
	int mid = (l+r)>>1;
	build(t[x].lc, l, mid);
	build(t[x].rc, mid+1, r);
}

int push_down(int x, int l, int r){
	int mid = (l+r)>>1;
	if (t[x].lz){
		int ll = t[x].lz;
		t[t[x].lc].val += ll;
		t[t[x].lc].lz += ll;
		t[t[x].rc].val += ll;
		t[t[x].rc].lz += ll;
		t[x].lz = 0;
	}
	return mid;
}

void push_up(int x){
	t[x].val = max(t[t[x].lc].val, t[t[x].rc].val);
}

void add(int x, int l, int r, int ql, int qr, int v){
	if (ql <= l && qr >= r){
		t[x].val += v;
		t[x].lz += v;
		return;
	}
	int mid = push_down(x, l, r);
	if (ql <= mid) add(t[x].lc, l, mid, ql, qr, v);
	if (qr > mid) add(t[x].rc, mid+1, q, ql, qr, v);
	push_up(x);
}

int qry(int x, int l, int r, int ql, int qr){
	if (ql <= l && qr >= r) return t[x].val;
	int mid = push_down(x, l, r);
	int ans = 0;
	if (ql <= mid) ans = max(ans, qry(t[x].lc, l, mid, ql, qr));
	if (qr > mid) ans = max(ans, qry(t[x].rc, mid+1,r, ql, qr));
	return ans;
}