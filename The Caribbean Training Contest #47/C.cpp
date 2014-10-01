#include <bits/stdc++.h>

using namespace std;

#define MAXN 4000
#define N 6

int num[N + 10];

int dp[MAXN];
int vis[MAXN];
int cont;
double ans;
int maxi;

queue <pair <int, int> > cola;

void mete(int x, int y){
	if(vis[x + 1000] == cont || x > 1000 || x < -1000)
		return;
	vis[x + 1000] = cont;
	if(x <= 100 && x > 0){
		ans += y;
		maxi = max(maxi, y);
	}
	cola.push(make_pair(x, y));
}

int main(){
	int T;
	cin >> T;
	while(T--){
		cont++;
		ans = 0.0;
		maxi = 0;
		for(int i = 0; i < N; i++){
			cin >> num[i];
			vis[num[i] + 1000] = cont;
			cola.push(make_pair(num[i], 1));
		}
		while(!cola.empty()){
			pair <int, int> now = cola.front();
			cola.pop();
			for(int i = 0; i < N; i++){
				mete(now.first - num[i], now.second +  1);
				mete(now.first + num[i], now.second +  1);
			}
		}
		printf("%.2lf %d\n", ans / 100.0 + 0.06, maxi);
	}
	return 0;
}