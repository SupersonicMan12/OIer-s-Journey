#pragma once

#include <bits/stdc++.h>
using namespace std;

void add_element(std::string x);
bool check_element(std::string x);
void compile_set();

void qry(int l, int r, int n){
	if (l == r) return;
	int mid = (l+r)>>1;
	for (int i = l; i <= mid; i++){
		string q; 
		for (int j = 0; j < l; j++) q.push_back('1');
		for (int j = l; j < i; j++) q.push_back('0');
		q.push_back('1');
		for (int j = i+1; j <= r; j++) q.push_back('0');
		for (int j = r+1; j < n; j++) q.push_back('1');
		add_element(q);
	}
	qry(l , mid, n);
	qry(mid+1, r, n);
}

vector<int> solve(int l, int r, vector<int> val, int n){
	if (l == r) return val;
	int mid = (l+r)>>1;
	vector<int> vleft, vright;
	char st[128];
	for (int j = 0; j < n; j++) st[j] = '1';
	for (auto y: val) st[y] = '0';
	for (auto x : val){
		string s; 
		for (int j = 0; j < x; j++) s.push_back(st[j]);
		s.push_back('1');
		for (int j = x+1; j < n; j++) s.push_back(st[j]);
		if (check_element(s)){
			vleft.push_back(x);
		} else {
			vright.push_back(x);
		}
	}
	vector<int> left = solve(l, mid, vleft, n);
	vector<int> right = solve(mid+1, r, vright, n);
	int p = 0;
	for (int x : left) val[p++] = x;
	for (int x : right) val[p++] = x;
	return val;
}

vector<int> restore_permutation(int n, int w, int r){
	qry(0, n-1, n);
	compile_set();
	vector<int> cand;
	for (int i = 0; i < n; i++) cand.push_back(i);
	vector<int> GOTO = solve(0, n-1, cand, n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++){
		ans[GOTO[i]] = i;
	}
	return ans;
}





