#include <bits/stdc++.h>
using namespace std;

int H, W, h, w, N;
pair<int,int> block[200005];

int main(){
	cin >> H >> W >> h >> w >> N;
	for (int i = 1; i <= N; i++){
		cin >> block[i].first >> block[i].second;	
	}
	sort(block+1, block+N+1);
	

	return 0;
}