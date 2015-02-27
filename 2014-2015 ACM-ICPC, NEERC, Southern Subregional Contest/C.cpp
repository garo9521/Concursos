#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
#define pii pair <int, int>


vector <int> E[MAXN];
int hijos[MAXN];

vector <int> Eheavy[MAXN];

vector < pair < int, int > > datos[MAXN];
string elementos[MAXN];
int cont2;
map <string, int> mapeo;
int cont, tamNodo;

pair <int, int> nodos[MAXN];
int grafo[MAXN];
bool chosto[MAXN];


int f(int nodo, int padre){
	int sum = 0;
	int hijoMax;
	int maxi = -1;
	for(vector <int> :: iterator it = E[nodo].begin(); it != E[nodo].end(); ++it){
		if(*it != padre){
			int a = f(*it, nodo);
			if(a > maxi){
				maxi = a;
				hijoMax = *it;
			}
			sum += a;
		}
	}
	if(sum < maxi * 2){
		Eheavy[nodo].push_back(hijoMax);
		Eheavy[hijoMax].push_back(nodo);
		chosto[nodo] = true;
		chosto[hijoMax] = true;
	}
	return hijos[nodo] = sum + 1;
}

set < pair <int, pii > > superNodo[MAXN];
int nuevoNodo[MAXN];

int dfs(int nodo, int padre, int SNodo, int nivel){
	nuevoNodo[nodo] = SNodo;
	grafo[SNodo] = nuevoNodo[padre];
	for(int i = 0; i < datos[nodo].size(); i++)
		superNodo[SNodo].insert(make_pair(datos[nodo][i].first, make_pair(nivel, datos[nodo][i].second)));
	
	for(int i = 0; i < E[nodo].size(); i++){
		if(E[nodo][i] == padre)
			continue;
		if(chosto[E[nodo][i]] && chosto[nodo])
			dfs(E[nodo][i], nodo, SNodo, nivel + 1);
		else
			dfs(E[nodo][i], nodo, tamNodo++, 0);
	}
}

int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		for(int j = 0; j < b; j++){
			string cadena;
			cin >> cadena;
			string c = "";
			int k;
			for(k = 0; cadena[k]; k++){
				if(cadena[k] == '='){
					break;
				}
				c = c + cadena[k];
			}
			string d = "";
			for(k++ ; cadena[k]; k++)
				d += cadena[k];
			if(mapeo.find(c) == mapeo.end())
				mapeo[c] = cont++;
			elementos[cont] = d;
			datos[i].push_back(make_pair(mapeo[c], ++cont2));
			
		}
		a--;
		E[a].push_back(i);
		E[i].push_back(a);
	}
	f(0, -1);
	dfs(0, -1, tamNodo++, 0);
	for(int i = 0; i < N; i++)
		cout << grafo[i] << endl;
	return 0;
}