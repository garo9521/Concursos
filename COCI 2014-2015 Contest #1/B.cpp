#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define MAXN 1000005
#define INF (1 << 30)


int main(){
	int N;
	cin >> N;
	int minX, minY;
	int maxX, maxY;
	minX = minY = INF;
	maxX = maxY = -INF;
	
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		minX = min(a, minX);
		maxX = max(a, maxX);
		minY = min(b, minY);
		maxY = max(b, maxY);
	}
	int area = max(maxX -  minX, maxY - minY);
	cout << area * area << endl;
	return 0;
}