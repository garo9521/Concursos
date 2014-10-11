#include <bits/stdc++.h>

#define MAXN 1005

using namespace std;
int fil[MAXN];
int col[MAXN];
char cadena[MAXN];

int main(){
	int T;
	scanf("%d", &T);
	for(int caso = 1; caso <= T; caso++){
		print("Case %d: ", caso);
		int N, M;
		scanf("%d%d", &N, &M);
		int total = 0;
		for(int i = 0; i < N; i++)
			fil[i] = 0;
		for(int i = 0; i < M; i++)
			col[i] = 0;
		
		for(int i = 0; i < N; i++){
			scanf("%s", cadena);
			for(int j = 0; cadena[j]; j++){
				if(cadena[j] == '1'){
					col[j]++;
					fil[i]++;
					total++;
				}
			}
		}
		if(total % N && total % M)
			puts("impossible");
		else if(total % N == 0 && total % M == 0){
			int c = total / N;
			for(int i = 0; i < N; i++)
				fil[i] -= c;
			c = total / M;
			for(int i = 0; i < M; i++)
				col[i] -= c;
			ans = 0;
			for(int i = 0; i < N; i++){
				if(fil[i] < 0){
					ans -= fil[i];
					fil[i + 1] += fil[i];
				}else{
					ans += fil[i];
					fil[i + i] -= fil[i];
				}
			}
			for(int i = 0; i < M; i++){
				if(col[i] < 0){
					ans -= col[i];
					col[i + 1] += col[i];
				}else{
					ans += col[i];
					col[i + i] -= col[i];
				}
			}
			printf("both %d\n", ans);
		}else if(total % N == 0){
			int c = total / N;
			for(int i = 0; i < N; i++)
				fil[i] -= c;
			ans = 0;
			for(int i = 0; i < N; i++){
				if(fil[i] < 0){
					ans -= fil[i];
					fil[i + 1] += fil[i];
				}else{
					ans += fil[i];
					fil[i + i] -= fil[i];
				}
			}
			printf("row %d\n", ans);
		}else{
			int c = total / M;
			for(int i = 0; i < M; i++)
				col[i] -= c;
			ans = 0;
			
			for(int i = 0; i < M; i++){
				if(col[i] < 0){
					ans -= col[i];
					col[i + 1] += col[i];
				}else{
					ans += col[i];
					col[i + i] -= col[i];
				}
			}
			printf("column %d\n", ans);
		}
		
	}
	return 0;
}