#include <bits/stdc++.h>
using namespace std;

vector<int> find_subset(int l, int u, vector<int> w){
	int n = w.size();
	pair<int,int> P[200005];
	for (int i = 0; i < n; i++){
		P[i].first = w[i];
		P[i].second = i;
	}
	vector<int> ans;
	sort(P,P+n);
	long long suma = 0;
	int i;
	for (i = 0; i < n; i++){
		suma += P[i].first;
		if (suma >= l) {
			if (suma <= u){
				for (int j = 0; j <= i; j++){
					ans.push_back(P[j].second);
				}
				return ans;
			}
			suma -= P[i].first; 
			i--;
			break;
		}
	}
	for (int j = i+1; j < n; j++){
		suma += P[j].first;
		suma -= P[j-i-1].first;
		if (suma >= l && suma <= u){
			for (int k = j-i; k <= j; k++){
				ans.push_back(P[k].second);
				// cout << P[k].second << ' ';
			}
			return ans;
		}
	}
	vector<int> mt;
	return mt;
}


int main() {
    int n, l, u;
    assert(3 == scanf("%d %d %d", &n, &l, &u));
    std::vector<int> w(n);
    for (int i = 0; i < n; i++)
        assert(1 == scanf("%d", &w[i]));
    std::vector<int> result = find_subset(l, u, w);
    
    printf("%d\n", (int)result.size());
    for (int i = 0; i < (int)result.size(); i++)
        printf("%d%c", result[i], " \n"[i == (int)result.size() - 1]);
}


