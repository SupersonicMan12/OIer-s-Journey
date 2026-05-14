#include <bits/stdc++.h>
using namespace std;
int b, n, d, m, M,MM;
int a[100005];
struct P2D{
	int d1, d2;
	int x, y;
	bool operator<(const P2D &other)const{
		return d1 < other.d1;
	}
} P[100005];

struct P3D{
	int d1, d2, d3, d4;
	int x, y, z;
	bool operator<(const P3D &other)const{
		return d1 < other.d1;
	}
} Q[100005];


int t[15005];
void add(int x){
	x += m;
	for (;x<=M;x+=(x&(-x))) t[x]++;
}
void rmv(int x){
	x += m;
	for (;x<=M;x+=(x&(-x))) t[x]--;
}
// int kth(int k){
// 	int x = 0;
// 	for (int i = (1<<12); i; i >>= 1){
// 		if ((x+i) <= m && t[x+i] < k){
// 			x += i;
// 			k -= t[x+i];
// 		}
// 	}
// 	return x+1;
// }
int qry(int x){
	x += m;
	int s = 0;
	for (;x;x-=(x&(-x))){
		s += t[x];
	}
	return s;
}
int qry(int l, int r){
	if (l < -m+1) l = -m+1;
	if (r > m-1) r = m-1;
	return qry(r)-qry(l-1);
}


int tt[303][303][303];
void add(int x, int y, int z, int v){
	x += 2*m; y += 2*m; z += 2*m;
	for (int i = x; i<=MM; i+=(i&(-i))) 
	for (int j = y; j<=MM; j+=(j&(-j)))
	for (int k = z; k<=MM; k+=(k&(-k))){
		tt[i][j][k]+=v;
	}
}
int qry(int x, int y, int z){
	x += 2*m; y += 2*m; z += 2*m;
	int s = 0;
	for (int i = x; i; i-=(i&(-i))) 
	for (int j = y; j; j-=(j&(-j)))
	for (int k = z; k; k-=(k&(-k)))
	{
		s += tt[i][j][k];
	}
	return s;
}
int qry(int l1, int r1, int l2, int r2, int l3, int r3){
	int lim = 2*m-1;
	if (l1 < -lim) l1 = -lim;
	if (r1 > lim) r1 = lim;
	if (l2 < -lim) l2 = -lim;
	if (r2 > lim) r2 = lim;
	if (l3 < -lim) l3 = -lim;
	if (r3 > lim) r3 = lim;
	return qry(r1, r2, r3)-qry(r1, r2, l3-1)-qry(r1, l2-1, r3)-qry(l1-1, r2, r3)
	+ qry(r1, l2-1, l3-1)+qry(l1-1, l2-1, r3)+qry(l1-1, r2, l3-1)-qry(l1-1,l2-1,l3-1);
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> b >> n >> d >> m;
	
	if (b == 1){
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a+1, a+n+1);
		int l = 1;
		long long ans = 0;
		for (int r = 1; r <= n; r++){
			while (l<r && a[r]-a[l]>d) l++;
			ans += (r-l);
		}
		cout << ans << '\n';
	} else if (b == 2){
		M = 2*m-1;
		for (int i = 1; i <= n; i++){
			cin >> P[i].x >> P[i].y;
			P[i].d1 = P[i].x+P[i].y;
			P[i].d2 = P[i].x-P[i].y;
		}
		sort(P+1, P+n+1);
		int l = 1;
		long long ans = 0;
		for (int r = 1; r <= n; r++){
			while (l<r && P[r].d1-P[l].d1>d) {
				rmv(P[l++].d2);
			}
			ans += qry(P[r].d2-d, P[r].d2+d);
			add(P[r].d2);
		}
		cout << ans << '\n';
	} else {
		MM = 4*m;
		for (int i = 1; i <= n; i++){
			cin >> Q[i].x >> Q[i].y >> Q[i].z;
			Q[i].d1 = Q[i].x+Q[i].y+Q[i].z;
			Q[i].d2 = Q[i].x-Q[i].y+Q[i].z;
			Q[i].d3 = Q[i].x+Q[i].y-Q[i].z;
			Q[i].d4 = Q[i].x-Q[i].y-Q[i].z;
		}
		sort(Q+1, Q+n+1);
		int l = 1;
		long long ans = 0;
		for (int r = 1; r <= n; r++){
			while (l<r && Q[r].d1-Q[l].d1>d) {
				add(Q[l].d2, Q[l].d3, Q[l].d4, -1);
				l++;
			}
			ans += qry(Q[r].d2-d, Q[r].d2+d, Q[r].d3-d, Q[r].d3+d, Q[r].d4-d, Q[r].d4+d);
			add(Q[r].d2, Q[r].d3, Q[r].d4, 1);
		}
		cout << ans << '\n';
	}

	return 0;
}