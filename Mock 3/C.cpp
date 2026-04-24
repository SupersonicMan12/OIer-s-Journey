#include <bits/stdc++.h>
using namespace std;

const int SENT = 18181818;
int n, m, q;
int x[100005], y[100005];
int ka[100005];
int a[100005];
int nxt[100005];
int ans[100005];
int cnt[100005];
vector<int> G[100005];
vector<pair<int,int>> loc[100005];

void s4(){
	for (int i = 1; i <= q; i++){
		cin >> ka[i];
		int last;
		for (int j = 0; j < ka[i]; j++){
			int xx; cin >> xx; 
			G[i].push_back(xx);
			loc[xx].push_back({i,j});
			if (j != 0 && last == xx-1) cnt[i]++;
			last = xx;
		}
		if (cnt[i]==ka[i]-1){
			ans[i] = 0;
		} else {
			ans[i] = SENT;
		}
	}
	for (int i = 1; i <= m; i++){
		int xx = x[i], yy = y[i];
		int pt1 = 0, pt2 = 0;
		int xmax = loc[a[xx]].size(), ymax = loc[a[yy]].size();
		while (pt1 < xmax || pt2 < ymax){
			if (pt1 == xmax || loc[a[yy]][pt2].first < loc[a[xx]][pt1].first){
				int qry = loc[a[yy]][pt2].first;
				if (ans[qry] == SENT) {
					int j2 = loc[a[yy]][pt2].second;
					if (xx!=yy-1 && j2>0 && a[yy-1] == G[qry][j2-1]) cnt[qry]--;
					if (yy<n && j2+1 < ka[qry] && G[qry][j2+1] == a[yy+1]) cnt[qry]--;
					swap(a[xx], a[yy]);
					if (xx!=yy-1 && j2>0 && a[yy-1] == G[qry][j2-1]) cnt[qry]++;
					if (yy<n && j2+1 < ka[qry] && G[qry][j2+1] == a[yy+1]) cnt[qry]++;
					swap(a[xx], a[yy]);
					if (cnt[qry]==ka[qry]-1){
						ans[qry] = i;
					}
				}
				pt2++;
			} else if (pt2 == ymax || loc[a[xx]][pt1].first < loc[a[yy]][pt2].first){
				int qry = loc[a[xx]][pt1].first;
				if (ans[qry] == SENT){
					int j1 = loc[a[xx]][pt1].second;
					if (xx>1 && (j1>0) && a[xx-1] == G[qry][j1-1]) cnt[qry]--;
					if (j1+1<ka[qry] && G[qry][j1+1] == a[xx+1]) cnt[qry]--;
					swap(a[xx], a[yy]);
					if (xx>1 && (j1>0) && a[xx-1] == G[qry][j1-1]) cnt[qry]++;
					if (j1+1<ka[qry] && G[qry][j1+1] == a[xx+1]) cnt[qry]++;
					swap(a[xx], a[yy]);					
					if (cnt[qry]==ka[qry]-1){
						ans[qry] = i;
					}
				}
				pt1++;
			} else if (loc[a[xx]][pt1].first==loc[a[yy]][pt2].first){
				int qry = loc[a[xx]][pt1].first;
				if (ans[qry] == SENT){
					int j1 = loc[a[xx]][pt1].second;
					int j2 = loc[a[yy]][pt2].second;
					if (xx>1 && (j1>0) && a[xx-1] == G[qry][j1-1]) cnt[qry]--;
					if (j1+1<ka[qry] && G[qry][j1+1] == a[xx+1]) cnt[qry]--;
					if (xx!=yy-1 && j2>0 && a[yy-1] == G[qry][j2-1]) cnt[qry]--;
					if (yy<n && j2+1 < ka[qry] && G[qry][j2+1] == a[yy+1]) cnt[qry]--;
					swap(a[xx], a[yy]);
					if (xx>1 && (j1>0) && a[xx-1] == G[qry][j1-1]) cnt[qry]++;
					if (j1+1<ka[qry] && G[qry][j1+1] == a[xx+1]) cnt[qry]++;
					if (xx!=yy-1 && j2>0 && a[yy-1] == G[qry][j2-1]) cnt[qry]++;
					if (yy<n && j2+1 < ka[qry] && G[qry][j2+1] == a[yy+1]) cnt[qry]++;
					swap(a[xx], a[yy]);
					if (cnt[qry]==ka[qry]-1){
						ans[qry] = i;
					}
				}
				pt1++; pt2++;
			} 
		}
		swap(a[xx], a[yy]);
	}
	for (int i = 1; i <= q; i++){
		cout << ans[i] << '\n';
	}
}

void s3(){
	for (int i = 1; i <= q; i++){
		int k; cin >> k;
		int head; cin >> head;
		int last = head, curr = 0;
		for (int j = 2; j <= k; j++){
			int xx; cin >> xx;
			nxt[last] = xx;
			if (last==xx-1) curr++;
			last = xx;
		}

		if (curr == k-1){
			cout << 0 << '\n';
		} else {
			for (int j = 1; j <= m; j++){
				if (x[j]>1 && nxt[a[x[j]-1]] == a[x[j]]) curr--;
				if (nxt[a[x[j]]] == a[x[j]+1]) curr--;
				if (x[j]!=y[j]-1 && nxt[a[y[j]-1]] == a[y[j]]) curr--;
				if (y[j]<n && nxt[a[y[j]]] == a[y[j]+1]) curr--;
				swap(a[x[j]], a[y[j]]);
				if (x[j]>1 && nxt[a[x[j]-1]] == a[x[j]]) curr++;
				if (nxt[a[x[j]]] == a[x[j]+1]) curr++;
				if (x[j]!=y[j]-1 && nxt[a[y[j]-1]] == a[y[j]]) curr++;
				if (y[j]<n && nxt[a[y[j]]] == a[y[j]+1]) curr++;
				if (curr == k-1) {
					cout << j << '\n';
					for (int jj = j; jj >= 1; jj--){
						swap(a[x[jj]], a[y[jj]]);
					}
					break;
				}
			}
		}

		last = head;
		for (int j = 2; j <= k; j++){
			int tmp = nxt[last];
			nxt[last] = 0;
			last = tmp;
		}
	}
}

// s2 ecosystem:

map<vector<int>, int> first;

// 8! * 8 * 7 affordable
void addsegs(int t){
    for (int l = 1; l <= n; l++){
        vector<int> cur;
        for (int r = l; r <= n; r++){
            cur.push_back(a[r]);
            if (!first.count(cur)) first[cur] = t;
        }
    }
}

void s2(){
    addsegs(0);
    for (int i = 1; i <= m; i++){
        swap(a[x[i]], a[y[i]]);
        addsegs(i);
    }

    for (int i = 1; i <= q; i++){
        int k; cin >> k;
        vector<int> b(k);
        for (int i = 0; i < k; i++) cin >> b[i];
        cout << first[b] << '\n';
    }
}

int main(){
	freopen("firstsight.in", "r", stdin);
	freopen("firstsight.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++){
		a[i]=i;
	}
	for (int i = 1; i <= m; i++){
		cin >> x[i] >> y[i];
		if (x[i] > y[i]) swap(x[i], y[i]);
	}
	
	//if (n >= 10000) s4();
	if (n <= 8) s2();
	else s3(); // if (m*q <= 200000) 
	return 0;
}


