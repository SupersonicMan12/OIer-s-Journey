// Find the nth multiple of (10^k-1) such that does not contain 9.
// k <= 18, n <= 1e18
// The sum of l segments of k must be a multiple of (10^k-1)

#include <bits/stdc++.h>
using namespace std;

const __int128 LIMIT = (__int128)2e18;
long long tmp; int k, L; 
__int128 n, M;
int digit[45][20];
// how much sum, how many digits caused this
__int128 dp[430][45];
// how much carry
__int128 dpp[2][45];
int ss[25];

__int128 addcap(__int128 a, __int128 b) {
    a += b;
    if (a > LIMIT) return LIMIT;
    return a;
}

__int128 mulcap(__int128 a, __int128 b) {
    if (a == 0 || b == 0) return 0;
    if (a > LIMIT / b) return LIMIT;
    a *= b;
    if (a > LIMIT) return LIMIT;
    return a;
}

void prec() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int j = 1; j <= L; j++) {
        for (int s = 0; s <= 8 * j; s++) {
            __int128 val = 0;
            for (int d = 0; d <= 8 && d <= s; d++){
                val = addcap(val, dp[s - d][j - 1]);
            }
            dp[s][j] = val;
        }
    }
}

// L segments of k
__int128 ways(){
	__int128 cnt = 0;
	// x is multiple
	for (int x = 1; x <= L; x++){
		__int128 S = M*x;
		int cc = 0;
		memset(ss, 0, sizeof(ss));
		while (S > 0){
			ss[cc++] = (int)(S%10);
			S /= 10;
		}
		// find number of ways to construct the other digits with sum S
		memset(dpp, 0, sizeof(dpp));
		dpp[0][0] = 1;
		// each column
		for (int i = 0, now = 1; i < k; i++, now ^= 1){
			memset(dpp[now], 0, sizeof(dpp[now]));
			int free = 0, fixed = 0;
			for (int j = 0; j < L; j++){
				if (digit[j][i]==-1) free++;
				else fixed += digit[j][i];
			}
			for (int oldC = 0; oldC <= L; oldC++){
				if (!dpp[now^1][oldC]) continue;
				for (int newC = 0; newC <= L; newC++){
					int need = 10*newC + ss[i] - oldC - fixed;
					if (need < 0) continue;
					if (need > 8 * free) break;
					dpp[now][newC] = addcap(dpp[now][newC], 
						mulcap(dpp[now^1][oldC], dp[need][free]));
				}
			}
		}
		cnt = addcap(cnt, dpp[k%2][10*ss[k+1]+ss[k]]);
	}
	return cnt;
}

string divide(const string& s, __int128 d){
	string ans = "";
	__int128 rem = 0;
	bool started = 0;
	for (char c: s){
		rem = rem*10+(c-'0');
		int digitq = (int)(rem/d);
		rem %= d;
		if (digitq != 0 || started){
			ans.push_back(char('0'+digitq));
			started = 1;
		}
	}
	if (!started) return "0";
	return ans;
}

int main(){
	cin >> k >> tmp;
	n = (__int128)tmp;
	M = 1; 
	for (int i = 1; i <= k; i++) M *= 10; 
	M--;
	L = (40+k-1)/k;

	// Considering digit: i*k+j
	memset(digit, -1, sizeof(digit));
	prec();
	__int128 total = 0;
	for (int i = L-1; i >= 0; i--){
		for (int j = k-1; j >= 0; j--){
			digit[i][j] = 0;
            __int128 last = ways();
            while (digit[i][j] < 8 && total + last < n) {
                total += last;
                digit[i][j]++;
                last = ways();
            }
		}
	}
	string mult = "";
    bool start = 0;
    for (int i = L-1; i >= 0; i--){
        for (int j = k-1; j >= 0; j--){
            if (!start && digit[i][j] == 0) continue;
            start = 1;
            mult.push_back(char('0' + digit[i][j]));
        }
    }
    if (!start) mult = "0";

    cout << divide(mult, M) << '\n';

	return 0;
}


