#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define MAXN 500005
#define INF (1 << 30)

int aristas[MAXN];

vector <int> E[MAXN];
bitset <MAXN> ciclo;

vector <int> cycle;
char vis[MAXN];
int costo[MAXN][2];
int dp[MAXN][2];
bitset <MAXN> VIS[2];
int DP[MAXN];


void busca(int nodo){
	if(vis[nodo] == 2)
		return;
	if(vis[nodo] == 1){
		vis[nodo] = 2;
		ciclo[nodo] = 1;
		cycle.push_back(nodo);
		busca(aristas[nodo]);
	}else{
		vis[nodo] = 1;
		busca(aristas[nodo]);
		vis[nodo] = 2;
	}
}

int f(int nodo, int color){
	if(VIS[nodo][color])
		return dp[nodo][color];
	VIS[nodo][color] = 1;
	int sum = 0, sum2 = 0;
	for(int i = 0; i < E[nodo].size(); i++)
		sum += max(f(E[nodo][i], color ^ 1), color == 1 ? 0 : f(E[nodo][i], color));

	return dp[nodo][color] = color + sum;
}

int main(){
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		int a;
		cin >> a;
		aristas[i] = a;
		E[a].push_back(i);
	}
	for(int i = 1; i <= N; i++){
		if(!vis[i]){
			busca(i);
		}
	}
	for(int i = 0; i < cycle.size(); i++){
		int nodo = cycle[i];
		for(int j = 0; j < E[nodo].size(); j++){
			if(ciclo[E[nodo][j]])
				continue;
			costo[i][0] += max(f(E[nodo][j], 1), f(E[nodo][j], 0));
			costo[i][1] += f(E[nodo][j], 0);
		}
	}
	for(int i = cycle.size() - 1; i > 0; i--)
		DP[i] = max(DP[i + 2] + 1 + costo[i][1] + costo[i + 1][0], DP[i + 1] + costo[i][0]);
	int ans = DP[1] + costo[0][0];
	for(int i = 0; i <= N; i++)
		DP[i] = 0;
	for(int i = cycle.size() - 2; i > 1; i--)
		DP[i] = max(DP[i + 2] + 1 + costo[i][1] + costo[i + 1][0], DP[i + 1] + costo[i][0]);
	ans = max(ans, costo[0][1] + 1 + costo[1][0] + DP[2] + (cycle.size() != 2 ? costo[cycle.size() - 1][0] : 0));
	cout << ans << endl;
	return 0;
}
