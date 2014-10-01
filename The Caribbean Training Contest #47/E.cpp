#include <bits/stdc++.h>

using namespace std;

#define MAXN 2005

int bin(int x, int y, int n){
	int ini = 0, fin = n, medio;
	while(ini < fin){
		medio = (ini + fin) /  2;
		if(x * medio - y * (n - medio) <= 0) ini = medio + 1;
		else fin = medio;
	}
	return x * ini - y * (n - fin);
}


int main(){
	int N, M;
	cin >> N >> M;
	int ans = 1 << 30;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		ans = min(ans, bin(a, b, N));
	}
	cout << ans << endl;
	return 0;
}