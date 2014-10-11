#include <bits/stdc++.h>

using namespace std;

#define MAXN 2005

char mapa[MAXN][MAXN];
int movs[4][2] = {{1, 0},
				  {0, 1},
				  {-1, 0},
				  {0, -1}
				 };
bool vis[MAXN][MAXN];

int main(){
	
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> mapa[i];
		for(int j = 0; j < M; j++)
			mapa[i][j] -= '0';
	}
	int ans = 0;
	string a;
	cin >> a;
	int x = 0, y = 0;
	int pos = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == 'R'){
			pos++;
			if(pos < 0)
				pos += 4;
		}else if(a[i] == 'L'){
			pos--;
			if(pos > 3)
				pos -= 4;
			
		}else if(a[i] == 'M'){
			if(pos == 0 ){
				ans += mapa[y][x];
				if(!vis[y][x]){
					vis[y][x] = true;
					mapa[y][x] /= 2;
				}
				if(y > 0){
					ans += mapa[y - 1][x];
					if(!vis[y - 1][x]){
						vis[y - 1][x] = true;
						mapa[y - 1][x] /= 2;
					}
				}
			}else if(pos == 1){
				if(y >= 0){
					ans += mapa[y][x];
					if(!vis[y][x]){
						vis[y][x] = true;
						mapa[y][x] /= 2;
					}
					if(x > 0){
						ans += mapa[y][x - 1];
						if(!vis[y][x - 1]){
							vis[y][x - 1] = true;
							mapa[y][x - 1] /= 2;
						}
					}
				}
			}else if(pos == 2){
				if(x > 0){
					ans += mapa[y][x - 1];
					if(!vis[y][x - 1]){
						vis[y][x - 1] = true;
						mapa[y][x - 1] /= 2;
					}
					if(y > 0){
						ans += mapa[y - 1][x - 1];
						if(!vis[y - 1][x - 1]){
							vis[y - 1][x - 1] = true;
							mapa[y - 1][x - 1] /= 2;
						}
					}
				}
			}else{
				if(y > 0){
					ans += mapa[y - 1][x];
					if(!vis[y - 1][x]){
						vis[y - 1][x] = true;
						mapa[y - 1][x] /= 2;
					}
					if(x > 0){
						ans += mapa[y - 1][x - 1];
						if(!vis[y - 1][x - 1]){
							vis[y - 1][x - 1] = true;
							mapa[y - 1][x - 1] /= 2;
						}
					}
				}
			}
			
			x += movs[pos][0];
			y += movs[pos][1];
		}
		
		
	}
	cout << ans << endl;
	return 0;
}