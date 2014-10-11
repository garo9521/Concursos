#include <bits/stdc++.h>

using namespace std;

#define MAXN 2005

int dp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int f(int x, int y){
	if(x <= 0 || y <= 0)
		return 0;
	if(vis[x][y])
		return dp[x][y];
	vis[x][y] = true;
	return dp[x][y] += f(x - 1, y) * 2 - f(x - 2, y) + f(x, y - 1)  * 2  - f(x, y - 2) - f(x - 1, y - 1)  ;
}

int main(){
	for(int i = 0; i <= 1000; i++){
		for(int j = 0; j <= 1000; j++){
			int raiz = sqrt(i * i + j * j);
			if(raiz * raiz == i * i + j * j){
				if(i == 0 || j == 0){
					dp[i + raiz][j + raiz] += raiz - 1;
				}else{
					dp[i + raiz][j + raiz] += (raiz - 1) * 2;
				}
			}
		}
	}
	cout << dp[4][4] << endl;
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		int a, b;
		cin >> a >> b;
		cout << "Case " << i << ": " << f(a, b) << endl;
	}
	return 0;
}
