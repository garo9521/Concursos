#include <bits/stdc++.h>

using namespace std;

#define MAXN 200
#define MOD 1000000007

long long int dp[MAXN][MAXN];
bool vis[MAXN][MAXN];

long long int f(int i, int j){
	if(vis[i][j])
		return dp[i][j];
	vis[i][j] = true;
	if(i == j)
		return dp[i][j] = 1;
	long long int ans = 0;
	for(int k = i; k < j; k++)
		ans = (ans + f(i, k) * f(k + 1, j)) % MOD;
	return dp[i][j] = ans;
}

int main(){
	int N;
	while(cin >> N)
		cout << f(1, N) << endl;
	
	return 0;
}