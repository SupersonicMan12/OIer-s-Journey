#include <bits/stdc++.h>
using namespace std;

int n, t;
bool g[505][505];
vector<int> seq[505];
bool aktiv[505];
vector<int> snake;

bool qry(int x, int y){
	cout << "? " << x << ' ' << y << endl;
	char c; cin >> c;
	return (c=='>');
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int d = j - i;
			bool dir;
			if (d < n / 2) dir = 1;
			else if (d > n / 2) dir = 0;
			else dir = 1;
			if (dir) g[i][j] = 1, g[j][i] = 0;
			else g[i][j] = 0, g[j][i] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			cout << g[i][j];
		cout << endl;
	}
	while (t--){
		snake.clear();
		memset(aktiv,0,sizeof(aktiv));
		int cnt = 0;
		for (int i = 1; i < n; i+=2){
			seq[++cnt].clear();
			if (qry(i,i+1)){
				seq[cnt].push_back(i);
				seq[cnt].push_back(i+1);
			} else {
				seq[cnt].push_back(i+1);
				seq[cnt].push_back(i);
			}
			aktiv[cnt] = 1;
		}
		if (n % 2) {
			seq[++cnt].clear();
			seq[cnt].push_back(n);
			aktiv[cnt] = 1;
		} 
		for (int i = 1; i < cnt; i++){
			bool flag = 0;
			for (int j = 1; j <= cnt; j++){
				if (!aktiv[j]) continue;
				for (int k = 1; k <= cnt; k++){
					if (j == k) continue;
					if (!aktiv[k]) continue;
					if (qry(seq[j].back(), seq[k][0])){
						for (int v : seq[k]){
							seq[j].push_back(v);
						}
						aktiv[k] = 0;
						flag = 1;
						break;
					}
				}
				if (flag) break;
			}
		}
		for (int i = 1; i <= cnt; i++){
			if (aktiv[i]){
				for (int v : seq[i]){
					snake.push_back(v);
				}
			}
		}
		// in 3n/2 we have a complete sequence
		int i;
		for (i=0;i<n-1;i++){
			if (qry(snake[n-1],snake[i])) break;
		}
		if (i == 0){
			cout << "! ";
			for (int v : snake){
				cout << v << ' ';
			}
			cout << endl;
		} else {
			for (int j = i; j < n-1; j++){
				int nj = j+1;
				if (qry(snake[j], snake[0]) && qry(snake[i-1],snake[nj])){
					cout << "! ";
					for (int k = i; k <= j; k++){
						cout << snake[k] << ' ';
					}
					for (int k = 0; k < i; k++){
						cout << snake[k] << ' ';
					}
					for (int k = nj; k <= n-1; k++){
						cout << snake[k] << ' ';
					}
					cout << endl;
					break;
				}
			}
		}
	}
	return 0;
}

