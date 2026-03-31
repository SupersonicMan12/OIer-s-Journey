#include <bits/stdc++.h>
using namespace std;

const double pi = 3.141592653589793;
double n;

int main(){
	cin >> n;
	double radius = n/2.0;
	double area = radius*radius*pi;
	cout << fixed << setprecision(10) << area << '\n';
	return 0;
}