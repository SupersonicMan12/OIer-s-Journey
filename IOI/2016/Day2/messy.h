#pragma once

#include <bits/stdc++.h>
using namespace std;

void add_element(std::string x);
bool check_element(std::string x);
void compile_set();

int nn;

string bin_st(int x){
	string s;
	for (int i = nn-1; i >= 0; i--){
		if ((x>>i)&1) s.push_back('1');
		else s.push_back('0');
	}
	return s;
}

int cnt(int x){
	int c = 0;
	for (int i = nn-1; i >= 0; i--){
		if ((x>>i)&1) c++;
	}
	return c;
}

vector<int> restore_permutation(int n, int w, int r){
	nn = n;
	// subtask 1
	if (n <= 8){
		for (int i = 1; i <= n; i++){
			string q;
			for (int j = 1; j <= i; j++) q.push_back('1');
			for (int j = i+1; j <= n; j++) q.push_back('0');
			add_element(q);
		}
		compile_set();
		int a[9]; a[0] = 0;
		int N = (1<<n);
		for (int i = 1; i < N; i++){
			if (check_element(bin_st(i))){
				a[cnt(i)] = i;
			}
		}
		vector<int> p(n);
		for (int i = 1; i <= n; i++){
			int diff = a[i]-a[i-1];
			int platz = -1;
			while (diff) {
				diff >>= 1; platz++;
			}
			platz = n-1-platz;
			p[platz] = i-1;
		}
		return p;
	} 
	// subtask 2
	else if (n == 32){ 
		for (int i = 1; i <= n; i++){
			string q;
			for (int j = 1; j <= i; j++) q.push_back('1');
			for (int j = i+1; j <= n; j++) q.push_back('0');
			add_element(q);
		}
		compile_set();
		long long curr = 0;
		vector<int> p(n);
		for (int num = 1; num <= n; num++){
			for (int nxt = 0; nxt < n; nxt++){
				if (curr&(1LL<<nxt)) continue;
				long long tmp = curr|(1LL<<nxt);
				if (check_element(bin_st(tmp))){
					// cout << n-nxt-1 << '\n';
					p[n-nxt-1] = num-1;
					curr = tmp;
					break;
				}
			}
		}
		return p;
	}	
}



