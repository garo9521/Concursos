#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

int mapa[MAXN][MAXN];

int main(){
	freopen("addictive.in", "r", stdin);
	freopen("addictive.out", "w", stdout);
	int N, M, C;
	cin >> N >> M >> C;
	int x = 0, y = 0;
	for(int i = 1; i <= C; i++){
		int a;
		cin >> a;
		while(a){
			mapa[y][x] = i;
			if(y & 1){
				x--;
			}else{
				x++;
			}
			if(x == M){
				y++;
				x = M - 1;
			}
			if(x == -1){
				y++;
				x = 0;
			}
			a--;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << mapa[i][j];
		}
		cout << endl;
	}
	return 0;
}