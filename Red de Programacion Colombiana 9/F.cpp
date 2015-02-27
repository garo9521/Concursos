#include <bits/stdc++.h>
#define INF 1000005
#define pii pair<int,int>
#define psi pair<string,pii>
#define MOD 1000000007
#define lli long long int

#define MAXN 105

using namespace std;

pair <int, pair <char ,int> > pasado[MAXN][MAXN * 100];
pair <int, pair <char ,int> > now[MAXN];
int total;

void borrar(int a,int n){
	int pos = max(total - a, 0);
	total = pos;
	for(int i=0;i<n;i++)
		now[i] = pasado[i][pos];
}

int main(){
	int N, M;
	cin >> N >> M;

	for(int i=0;i<N;i++){
		now[i].first = 0;
		now[i].second.first = 0;
		now[i].second.second = i + 1;
		pasado[i][0] = now[i];
	}
	while(M--){
		int a, c;
		string b;
		cin >> a >> b >> c;
		borrar(a, N);
		for(int i = 0; i < N; i++){
			now[i].first = pasado[i][total].first;
			now[i].second.first = b[i];
			now[i].second.second = pasado[i][total].second.second;
		}
		sort(now, now + N);
		int cont = 0;
		total++;
		pair <int, pair <char ,int> > ant = now[0];
		pasado[0][total].first = cont;
		pasado[0][total].second.first = now[0].second.first;
		pasado[0][total].second.second = now[0].second.second;
		for(int i = 1; i < N; i++){
			if(ant.first == now[i].first && ant.second.first == now[i].second.first){
				pasado[i][total].first = cont;
				pasado[i][total].second.first = now[i].second.first;
				pasado[i][total].second.second = now[i].second.second;
			}else{
				cont++;
				pasado[i][total].first = cont;
				pasado[i][total].second.first = now[i].second.first;
				pasado[i][total].second.second = now[i].second.second;
			}
		}
		printf("%d\n",now[c - 1].second.second);
	}
	return 0;
}
