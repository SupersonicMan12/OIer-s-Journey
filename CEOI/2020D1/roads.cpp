#include <bits/stdc++.h>
using namespace std;
#define db long double
const int N = 100050;
const db Pi = acos(-1.0),theta = Pi * (1.0 * 139 / 180),cost = cos(theta),sint = sin(theta);

struct point{
	db x,y; int realx,realy;
	void calc(){ 
		x = cost * realx - sint * realy;
		y = cost * realy + sint * realx; 
	}
} p[N<<1]; 

int n; db T;

struct line{
	int s,t; mutable int rmost; db k,b;
	void calc(){ 
		k = (p[s].y - p[t].y) / (p[s].x - p[t].x);
		b = p[s].y - k * p[s].x; 
	}
	bool operator < (const line &w) const{ 
		return k*T+b < w.k*T+w.b; 
	}
}tmp;
set<line>S; set<line>::iterator it;

struct Event{
	int id, tp; db x;
	bool operator<(const Event &w) const{ 
		return x < w.x; 
	}
} ev[N<<1];

void print(point a,point b){
	cout << a.realx << ' ' << a.realy << ' ' << b.realx << ' ' << b.realy << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n*2; i += 2){
		cin >> p[i].realx >> p[i].realy; 
		p[i].calc();
		cin >> p[i+1].realx >> p[i+1].realy;
		p[i+1].calc();
		if (p[i].x > p[i+1].x) swap(p[i],p[i+1]);
		ev[i].id = i, 		ev[i].tp = 1, 	ev[i].x = p[i].x;
		ev[i+1].id = i+1, 	ev[i+1].tp = 0, ev[i+1].x = p[i+1].x;
	}
	sort(ev+1,ev+2*n+1);

	// lower sentinel
	tmp.s = -1, tmp.t = tmp.rmost = 0, tmp.k = 0, tmp.b = -1e10; S.insert(tmp);

	for (int i = 1; i <= n*2; ++i){
		T = ev[i].x;
		// left endpoint, add line
		if (ev[i].tp){
			tmp.rmost = tmp.s = ev[i].id;
			tmp.t = ev[i].id+1;
			tmp.calc();
			// it now points to the line below the new line
			it = S.insert(tmp).first; --it;
			if (it->rmost) print(p[it->rmost],p[tmp.s]); 
			it->rmost = tmp.s;
		}
		else{
			tmp.s = ev[i].id-1; 
			tmp.t = ev[i].id;
			tmp.calc();
			it = S.find(tmp); --it;
			it->rmost = tmp.t; S.erase(tmp);
		}
	}
	return 0;
}
