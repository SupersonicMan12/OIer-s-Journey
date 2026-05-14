#include <bits/stdc++.h>
using namespace std;
int F, K, M;
struct Fish{
	int l, typ;
	bool operator<(const Fish &other) const{
		return l < other.l;
	}
} fish[500005];

int le[500005], ll[500005], raw[500005];
int lastType[500005], ccc[500005], cc[500005];
int mapTo[500005];
vector<int> V[500005];

int t[2000005];
void build(int x, int l, int r){
	if (l == r) {t[x] = 1; return;}
	int mid = (l+r)>>1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	t[x] = t[x<<1]*t[x<<1|1]%M;
}
void add(int x, int l, int r, int q){
	if (l == r) {
		t[x]=(t[x]+1)%M; return;
	}
	int mid = (l+r)>>1;
	if (q <= mid) add(x<<1, l, mid, q);
	if (q > mid) add(x<<1|1, mid+1, r, q);
	t[x] = t[x<<1]*t[x<<1|1]%M;
}

int qry(int x, int l, int r, int ql, int qr){
	if (qr < ql) return 1;
	if (l >= ql && r <= qr){
		return t[x];
	}
	int ans = 1;
	int mid = (l+r)>>1;
	if (ql <= mid) ans = ans*qry(x<<1, l, mid, ql, qr)%M;
	if (qr > mid) ans = ans*qry(x<<1|1, mid+1, r, ql, qr)%M;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> F >> K >> M; 
	memset(lastType, 0x3f, sizeof(lastType));
	for (int i = 1; i <= F; i++){
		cin >> fish[i].l >> fish[i].typ;
	}
	sort(fish+1, fish+F+1);
	for (int i = 1; i <= F; i++){
		lastType[fish[i].typ] = i;
	}
	vector<pair<int,int>> P;
	for (int i = 1; i <= K; i++){
		if (lastType[i]==0x3f3f3f3f) continue;
		P.push_back({lastType[i], i});
	}
	sort(P.begin(), P.end());
	int cnt = 0;
	for (auto [u, v]: P){
		// cout << u << v << endl;
		mapTo[v] = ++cnt;
		raw[cnt] = 1;
		ll[cnt] = fish[u].l;
	}
	for (int i = 1; i <= F; i++){
		// cout << fish[i].typ << ' ';
		fish[i].typ = mapTo[fish[i].typ];
		// cout << fish[i].typ << endl;
		ccc[fish[i].typ]++;
		V[fish[i].typ].push_back(fish[i].l);
		le[i] = fish[i].l;
	}
	long long ans = 0;
	int frontier = 1;
	build(1, 1, cnt);
	for (int i = 1; i <= F; i++){
		while (frontier <= F && le[frontier]*2<=le[i]) {
			add(1, 1, cnt, fish[frontier].typ);
			raw[fish[frontier].typ]++;
			frontier++;
		}
		cc[fish[i].typ]++;
		if (cc[fish[i].typ] == ccc[fish[i].typ]){
			// cout << i << endl;
			int tt = fish[i].typ;
			int own = raw[tt];
			long long full = 1, partial = (own-1+M)%M;
			// when full cc is taken, >= 2*l must be avoided
			int lb = lower_bound(ll+1, ll+cnt+1, 2*V[tt][own-1])-ll;
			full = full*qry(1, 1, cnt, 1, tt-1)%M;
			full = full*qry(1, 1, cnt, tt+1, lb-1)%M;
			// when partial cc is taken, all >= l must be avoided
			partial = partial*qry(1, 1, cnt, 1, tt-1)%M;
			ans = (ans+full+partial)%M;
			// cout << "CHANGED\n";
		}
		// cout << ans << '\n';
	}
	cout << ans << endl;
}





