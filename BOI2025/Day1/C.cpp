#include <bits/stdc++.h>
using namespace std;

int n;
bool which[3];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
map<tuple<int,int,int>, tuple<bool,bool,bool>> M;

void qs(int x, int y, int z){
	if (M.count({x,y,z})){
		auto k = M[{x, y, z}];
		which[0] = get<0>(k);
		which[1] = get<1>(k);
		which[2] = get<2>(k);
		return;
	}

	which[0]=which[1]=which[2]=0;
	cout << "? " << x << ' ' << y << ' ' << z << endl;
	int ax, ay, nn;
	cin >> nn;
	for (int i = 1; i <= nn; i++){
		cin >> ax >> ay;
		if (ax+ay==x+y) which[0] = 1;
		if (ax+ay==x+z) which[1] = 1;
		if (ax+ay==y+z) which[2] = 1;
	}

	M[{x,y,z}] = {which[0], which[1], which[2]};
	M[{x,z,y}] = {which[1], which[0], which[2]};
	M[{y,x,z}] = {which[0], which[2], which[1]};
	M[{y,z,x}] = {which[2], which[0], which[1]};
	M[{z,x,y}] = {which[1], which[2], which[0]};
	M[{z,y,x}] = {which[2], which[1], which[0]};
}

vector<int> rec(vector<int> &X){
	if (X.size() <= 2) return X;
	// to prevent failure in uv queries
	if (X.size() == 3) {
	    qs(X[0], X[1], X[2]);
	    if (!which[2]) return vector<int>{X[1], X[0], X[2]};
	    if (!which[1]) return vector<int>{X[0], X[1], X[2]};
	    if (!which[0]) return vector<int>{X[0], X[2], X[1]};
	    return X;
	}
	vector<int> U, V;
	int u, v;
	int x = X.size();
	while (1){
		bool bad = 0;
		u = rng()%x; v = rng()%x;
		while (v == u) v = rng()%x;
		U.clear(); V.clear();
		for (int i = 0; i < x; i++){
			if (i == u || i == v) continue;
			qs(X[u],X[v],X[i]);
			if (which[0]){
				bad = 1;
				break;
			} else if (which[1]){
				U.push_back(X[i]);
			} else {
				V.push_back(X[i]);
			}
		}
		if (!bad) break;
	}
	V.push_back(X[v]); V = rec(V); v = V.size();
	U.push_back(X[u]); U = rec(U); u = U.size();
	bool ur = 0, vr = 0;
	if (U.size() == 1){
		qs(V[0], V[1], U[0]);
		if (!which[1]) vr = 1;
	} else if (V.size() == 1){
		qs(U[0], U[1], V[0]);
		if (which[1]) ur = 1;
	} else {
		qs(V[0], V[1], U[0]);
		if (which[1]) {
			ur = 1, vr = 0;
		} else {
			qs(V[0], V[1], U[u-1]);
			if (which[1]){
				ur = vr = 0;
			} else {
				qs(V[v-1], V[v-2], U[0]);
				if (which[1]){
					ur = vr = 1;
				} else {
					ur = 0, vr = 1;
				}
			}
		}
	}
	if (ur) reverse(U.begin(), U.end());
	if (vr) reverse(V.begin(), V.end());
	vector<int> res;
	for (int uu : U) res.push_back(uu);
	for (int vv : V) res.push_back(vv);
	return res;
}

void solve(){
	cin >> n;
	M.clear();
	vector<int> XX;
	XX.clear();
	for (int i = 0; i < n; i++) XX.push_back(i);
	XX = rec(XX);
	cout << "! ";
	for (int v : XX) cout << v << ' ';
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T, K; cin >> T >> K;
	while (T--) solve();
	return 0;
}





