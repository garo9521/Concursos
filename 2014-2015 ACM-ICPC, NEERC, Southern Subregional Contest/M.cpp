#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define pii pair <int, int>
char cadena[MAXN];

vector< pair <int, pii > > letras[100];

void elimina(int x){
	for(int i = 0; i < 30; i++){
		
		while(letras[i].size() > 0){
			pair <int, pii > a;
			a = letras[i].back();
			if(a.first != x)
				break;
			letras[i].pop_back();
		}
	}
}

int main(){
	int N;
	cin >> N;
	int cont = 0;
	getchar();
	for(int i = 1; i <= N; i++){
		gets(cadena);
		for(int j = 0; cadena[j]; j++){
			if(cadena[j] == '{'){
				cont++;
			}else if(cadena[j] == '}'){
				elimina(cont);
				cont--;
			}else if(cadena[j] != ' '){
				if(letras[cadena[j] - 'a'].size() != 0)
					printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n	", i, j + 1, cadena[j], letras[cadena[j] - 'a'].back().second.first, letras[cadena[j] - 'a'].back().second.second);
				
				letras[cadena[j] - 'a'].push_back(make_pair(cont, make_pair(i, j + 1)));
			}
		}
	}
	return 0;
}