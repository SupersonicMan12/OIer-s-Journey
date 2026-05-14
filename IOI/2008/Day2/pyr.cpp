#include <bits/stdc++.h>
using namespace std;

int m, n, b, p;
vector<pair<int,int>> st[1000005];
vector<pair<int,int>> en[1000005];

int t[4000005],ls[4000005],rs[4000005],val[4000005];

void push_up(int x, int l, int r, int mid){
	if (val[x]){
		ls[x] = rs[x] = t[x] = 0;
	} else if (l == r){
		ls[x] = rs[x] = t[x] = 1;
	} else {
		ls[x] = (ls[x<<1]==(mid-l+1))?ls[x<<1]+ls[x<<1|1]:ls[x<<1];
		rs[x] = (rs[x<<1|1]==r-mid)?rs[x<<1|1]+rs[x<<1]:rs[x<<1|1];
		t[x] = max(t[x<<1], t[x<<1|1]);
		t[x] = max(t[x], rs[x<<1]+ls[x<<1|1]);
	}
}

void build(int x, int l, int r){
	if (l == r){
		ls[x]=rs[x]=t[x]=1;
		return;
	}
	int mid = (l+r)>>1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	push_up(x, l, r, mid);
}

void update(int x, int l, int r, int ql, int qr, int v){
	int mid = (l+r)>>1;
	if (l >= ql && r <= qr){
		val[x] += v;
		push_up(x, l, r, mid);
		return;
	}
	if (ql <= mid) update(x<<1, l, mid, ql, qr, v);
	if (qr > mid) update(x<<1|1, mid+1, r, ql, qr, v);
	push_up(x, l, r, mid);
}

void add_right(int x){
	for (auto [u, v]: st[x]){
		update(1, 1, n, u, v, 1);
	}
}

void remove_left(int x){
	for (auto [u, v]: en[x]){
		update(1, 1, n, u, v, -1);
	}
}

// subtask 2
int xla[30005], yla[30005], xra[30005], yra[30005], c[30005];
vector<tuple<int,int,int>> cont[1000005];

void add(int x, int l, int r, int ql, int qr, int v){
	if (l >= ql && r <= qr){
		t[x] += v;
		val[x] += v;
		return;
	}
	if (val[x]){
		val[x<<1] += val[x]; t[x<<1] += val[x];
		val[x<<1|1] += val[x]; t[x<<1|1] += val[x];
		val[x] = 0;
	}
	int mid = (l+r)>>1;
	if (ql <= mid) add(x<<1, l, mid, ql, qr, v);
	if (qr > mid) add(x<<1|1, mid+1, r, ql, qr, v);
	t[x] = min(t[x<<1], t[x<<1|1]);
}

void clear(int x, int l, int r){
	t[x] = val[x] = 0;
	if (l == r) return;
	int mid = (l+r)>>1;
	clear(x<<1, l, mid);
	clear(x<<1|1, mid+1, r);
}

bool check(int s){
	for (int i = 1; i <= m-s+2; i++){
		cont[i].clear();
	}
	for (int i = 1; i <= p; i++){
		int lb = max(yla[i]-s+1,1);
		int rb = min(n-s+1, yra[i]);
		cont[max(xla[i]-s+1, 1)].push_back({lb, rb, c[i]});
		cont[min(xra[i],m-s+1)+1].push_back({lb, rb, -c[i]});
	}
	clear(1, 1, n-s+1);
	for (int i = 1; i <= m-s+1; i++){
		for (auto [u, v, w]: cont[i]){
			add(1, 1, n-s+1, u, v, w);
		}
		if (t[1] <= b) return 1;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n >> b >> p;
	if (b == 0){
		for (int i = 1; i <= p; i++){
			int xl, xr, yl, yr, c; cin >> xl >> yl >> xr >> yr >> c;
			st[xl].push_back({yl, yr});
			en[xr].push_back({yl, yr});
		}
		int j = 0, ans = 0;
		build(1, 1, n);
		for (int i = 1; i <= m; i++){
			while (t[1] >= j-i+1 && j <= m){
				j++;
				if (j > m) break;
				add_right(j);
			}
			remove_left(i);
			ans = max(ans, j-i);
		}
		cout << ans << endl;
	} else {
		for (int i = 1; i <= p; i++){
			cin >> xla[i] >> yla[i] >> xra[i] >> yra[i] >> c[i];
		}
		int l = 1, r = min(n, m), ans = 0;
		while (l <= r){
			int mid = (l+r)>>1;
			if (check(mid)){
				l = mid+1;
				ans = mid;
			} else {
				r = mid-1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}