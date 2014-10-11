#include <bits/stdc++.h>

using namespace std;

#define LIM 100000

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	double a, c;
	int b;
	cin >> a >>  b >> c;
	c /= 100.0;
	double ini = 0.00001, fin = 100000000.0, medio;
	for(int i = 0; i < LIM; i++){
		medio = (ini + fin) / 2.0;
		double d = a;
		double x = 0.0, y = 0.0;
		double sum = 0.0;
		for(int i = 0; i < b; i++){
			x = d * c;
			y = (medio - x);
			d -= y;
		}
		if(d > 0)
			ini = medio;
		else fin = medio;
	}
	printf("%.5lf\n", ini);
	return 0;
}