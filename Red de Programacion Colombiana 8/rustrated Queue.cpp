#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005
#define MOD 1000000

char cadena[MAXN];
int N;
int vis[MAXN][MAXN];
int dp[MAXN][MAXN];
int cont;

int f(int x, int y){
    if(y < 0)
        return 0;
    if(vis[x][y] == cont)
        return dp[x][y];
    vis[x][y] = cont;
    if(x == N)
        return dp[x][y] = (y == 0 ? 1 : 0);
    if(cadena[x] == '(')
        return dp[x][y] = f(x + 1, y + 1);
    if(cadena[x] == ')')
        return dp[x][y] = f(x + 1, y - 1);
    return dp[x][y] = (f(x + 1, y + 1) + f(x + 1, y - 1) ) % MOD;
}

int main() {
    while(scanf("%s", cadena) != EOF){
        for(N = 0; cadena[N]; N++);
        cont++;
        cout << f(0, 0) << endl;
    }
	return 0;
}
