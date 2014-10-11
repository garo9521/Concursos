#include <bits/stdc++.h>

using namespace std;

#define MAXN 105

char mapa[MAXN][MAXN];
vector <int> E[MAXN * MAXN * 3];
int vis[MAXN * MAXN * 3];
int color;
double area[MAXN * MAXN * 3];
double f, f2;
pair <int, int> fig[MAXN * MAXN * 3];

void busca(int nodo){
	if(vis[nodo] == color)
		return;
	vis[nodo] = color;
	if(nodo % 3 == 1)
		f++;
	else f2++;
	for(int i = 0; i < E[nodo].size(); i++)
		busca(E[nodo][i]);

}

int main(){
	int T;
	scanf("%d", &T);
	for(int caso = 1; caso <= T; caso++){
		printf("Case %d:\n", caso);
		int N, M;
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; i++)
			scanf("%s", mapa[i]);
		int cont = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
                if(j + 1 != M){
                    if((mapa[i][j] == '0' && mapa[i][j + 1] == '0') || (mapa[i][j] == '1' && mapa[i][j + 1] == '1')){
                        E[cont + 1].push_back(cont + 3);
                        E[cont + 2].push_back(cont + 4);
                        E[cont + 3].push_back(cont + 1);
                        E[cont + 4].push_back(cont + 2);
                    }else if((mapa[i][j] == '0' && mapa[i][j + 1] == '1') || (mapa[i][j] == '1' && mapa[i][j + 1] == '0')){
                        E[cont + 1].push_back(cont + 4);
                        E[cont + 2].push_back(cont + 3);
                        E[cont + 4].push_back(cont + 1);
                        E[cont + 3].push_back(cont + 2);
                    }
                }
                if(i + 1 != N){
                    if((mapa[i][j] == '0' && mapa[i + 1][j] == '0')){
                        E[cont + 1].push_back(cont + M * 3);
                        E[cont + 2].push_back(cont + M * 3 + 1);
                        E[cont + M * 3].push_back(cont + 1);
                        E[cont + M * 3 + 1].push_back(cont + 2);
                    }else if((mapa[i][j] == '0' && mapa[i + 1][j] == '1')){
                        E[cont + 1].push_back(cont + M * 3 + 1);
                        E[cont + 2].push_back(cont + M * 3 + 2);
                        E[cont + M * 3 + 1].push_back(cont + 1);
                        E[cont + M * 3 + 2].push_back(cont + 2);
                    }else if((mapa[i][j] == '1' && mapa[i + 1][j] == '0')){
                        E[cont].push_back(cont + M * 3);
                        E[cont + 1].push_back(cont + M * 3 + 1);
                        E[cont + M * 3].push_back(cont);
                        E[cont + M * 3 + 1].push_back(cont + 1);
                    }else{
                        E[cont].push_back(cont + M * 3 + 1);
                        E[cont + 1].push_back(cont + M * 3 + 2);
                        E[cont + M * 3 + 1].push_back(cont );
                        E[cont + M * 3 + 2].push_back(cont + 1);
                    }
                }
				cont += 3;

			}
		}
		color = 0;
		for(int i = 0; i < cont; i++){
			if(!vis[i]){
				color++;
				f = f2 = 0;
				busca(i);

				area[color] = f * (4.0 - (M_PI / 2.0)) + f2 * (M_PI / 4.0);
				fig[color] = make_pair(f, f2);
			}
		}
		int Q;
		scanf("%d", &Q);
		while(Q--){
			int a, b;
			scanf("%d%d", &a, &b);
			int x = a / 2;
			int y = b / 2;
			int pos = x * M * 3 + y * 3;
			if(b == M * 2 && a == N * 2){
				x--;
				y--;
                if(mapa[x][y] == '0'){
                    printf("%.4lf\n", area[vis[cont - 1]]);
                }else{
                    printf("%.4lf\n", area[vis[cont - 2]]);
                }
			}else{
                if(b == M * 2){

                        y--;
                        pos -= 3;
                    if(mapa[x][y] == '0'){
                        if(a % 2 == 0){
                            printf("%.4lf\n", area[vis[pos + 1]]);
                        }else{
                            printf("0.0000\n");
                        }
                    }else{
                        if(a % 2 == 0){
                            printf("%.4lf\n", area[vis[pos + 2]]);
                        }else{
                            printf("0.0000\n");
                        }
                    }
                }else{
                    if(a == N * 2){
                        x--;
                        pos -= M * 3;
                        if(mapa[x][y] == '0'){
                            if(b % 2 == 0){
                                printf("%.4lf\n", area[vis[pos + 1]]);
                            }else{
                                printf("0.0000\n");
                            }
                        }else{
                            if(b % 2 == 0){
                                printf("%.4lf\n", area[vis[pos]]);
                            }else{
                                printf("0.0000\n");
                            }
                        }

                    }else{
                        if(mapa[x][y] == '0'){
                            if(a % 2 == 0 && b % 2 == 0){
                                printf("%.4lf\n", area[vis[pos]]);
                            }else if((a % 2 == 1 && b % 2 == 0) || (a % 2 == 0 && b % 2 == 1)){
                                printf("0.0000\n");
                            }else{
                                printf("%.4lf\n", area[vis[pos + 1]]);
                            }
                        }else{
                            if(a % 2 == 0 && b % 2 == 0){
                                printf("%.4lf\n", area[vis[pos + 1]]);
                            }else if((a % 2 == 1 && b % 2 == 0) || (a % 2 == 0 && b % 2 == 1)){
                                printf("0.0000\n");
                            }else{
                                printf("%.4lf\n", area[vis[pos + 1]]);
                            }
                        }
                    }
                }
			}
		}
		for(int i = 0; i < cont; i++)
            E[i].clear(), vis[i] = 0;
	}
	return 0;
}
