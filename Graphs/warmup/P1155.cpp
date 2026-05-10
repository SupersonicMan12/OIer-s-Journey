#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005], m[1005];
int assign[1005];
vector<int> G[1005];
stack<int> s1,s2;
string ans;
bool flag = 0;

void dfs(int x){
	for (int v : G[x]){
		if (assign[v]) {
			if (assign[v] == assign[x]) flag = 1;
			continue;
		}
		assign[v] = 3-assign[x];
		dfs(v);
	}
}

int main(){
	cin >> n;
	m[n+1] = 99999999;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--){
		m[i] = min(m[i+1], a[i]);
	}
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			if (a[i] > a[j]) continue;
			if (a[i] > m[j+1]){
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	// notice element 1 is assigned color 1
	for (int i = 1; i <= n; i++){
		if (!assign[i]){
			assign[i] = 1;
			dfs(i);
		}
	}
	if (flag){
		cout << 0 << endl;
		return 0;
	}
	int i = 1, need = 1;
	while (need <= n){
		if (assign[i]==1 && i <= n && (s1.empty()||s1.top()>a[i])){
			cout << "a ";
			s1.push(a[i]);
			i++;
		} else if (!s1.empty() && s1.top() == need){
			cout << "b ";
			s1.pop();
			need++;
		} else if (assign[i]==2 && i <= n && (s2.empty()||s2.top()>a[i])){
			cout << "c ";
			s2.push(a[i]);
			i++;
		} else {
			cout << "d ";
			s2.pop();
			need++;
		}
	}
	cout << endl;
	return 0;
}



