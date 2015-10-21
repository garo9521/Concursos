#include <bits/stdc++.h>

using namespace std;

long long int vis[1000][10];
long long int dp[1000][10];
long long int cont;
const long long int N = 30;
long long int C;

long long int f(long long int pos, long long int color){
	if(vis[pos][color] == cont)
		return dp[pos][color];
	vis[pos][color] = cont;
	if(pos == N){
		if(color == C)
			return dp[pos][color] = 0;
		return dp[pos][color] = 1;
	}
	return dp[pos][color] = f(pos + 1, (color + 1) % 3) + f(pos + 1, (color + 2) % 3);
}


int main(){
	long long	 int ans = 0;
	for(C = 0; C < 3; C++){
		cont++;
		ans += f(1, C);
	}
	cout << ans << endl;
	return 0;
}