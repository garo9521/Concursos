#include <bits/stdc++.h>

using namespace std;

#define rad (M_PI / 180.0)

int main(){
	int T;
	cin >> T;
	while(T--){
		double x1, y1, c1;
		cin >> y1 >> x1 >> c1;
		double T1 = (c1 ) * rad;
		double A1, B1, C1;
		A1 = sin(T1);
		B1 = -cos(T1);
		C1 = B1 * y1 - A1 * x1;
		double x2, y2, c2;
		cin >> y2 >> x2 >> c2;
		double T2 = (c2) * rad ;
		double A2, B2, C2;
		A2 = sin(T2);
		B2 = -cos(T2);
		C2 = B2 * y2 - A2 * x2;
		
		double delta = A1 * B2 - A2 * B1;
		double deltaY = A1 * C2 - A2 * C1;
		double deltaX = C1 * B2 - C2 * B1;
		printf("%.4lf %.4lf\n", deltaX / delta, deltaY / delta);
	}
	return 0;
}