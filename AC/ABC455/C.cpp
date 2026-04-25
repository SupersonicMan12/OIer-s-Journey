#include <bits/stdc++.h>
using namespace std;

int n, k; 
int a[300005];
map<int,int> M;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	long long suma = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		suma += a[i];
		if (M.count(a[i])){
			M[a[i]]++;
		} else {
			M[a[i]] = 1;
		}
	}
	vector<long long> V;
	for (auto [u, v]: M){
		V.push_back(1LL*v*u);
	}
	sort(V.begin(), V.end(), greater<long long>());
	int bd = min(k, (int)V.size());
	for (int i = 0; i < bd; i++){
		suma -= V[i];
	}
	cout << suma << endl;

	return 0;
}





