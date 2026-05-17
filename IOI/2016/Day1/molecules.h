#pragma once
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
