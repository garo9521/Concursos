#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define MAXN 1000005
#define INF (1 << 30)


pair <lld, lld> puntos[MAXN];

vector < pair <lld, pair<lld, lld> > > 	rectas;

vector < pair <lld, pair <lld, pair <lld, lld> > > > R;

int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> puntos[i].first >> puntos[i].second;
	sort(puntos, puntos + N);
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			
			lld A = puntos[i].second - puntos[j].second;
			lld B = puntos[j].first - puntos[i].first;
			lld C = puntos[j].second * puntos[i].first - puntos[i].second * puntos[j].first;
			lld MCD = __gcd(abs(A), __gcd(abs(B), abs(C)));
			A /= MCD;
			B /= MCD;
			C /= MCD;
			
			lld a = puntos[i].second - puntos[j].second;
			lld b = puntos[i].first - puntos[j].first;
			lld dist = a * a + b * b;
			
			if(A < 0){
				R.push_back(make_pair(-A, make_pair(-B, make_pair(-C, dist))));
			}else{
				R.push_back(make_pair(A, make_pair(B, make_pair(C, dist))));
			}
			if(b == 0 && a < 0){
				a = -(1 << 30);
				b = 1;					
			}else if(b == 0 && a > 0){
				a = 1 << 30;
				b = 1;
			}
			lld mcd = __gcd(a, b);
			a /= mcd;
			b /= mcd;
			rectas.push_back(make_pair(dist, make_pair(a, b)));
		}
	}
	sort(rectas.begin(), rectas.end());
	sort(R.begin(), R.end());
	pair <lld, pair <lld, lld > > ant = rectas[0];
	lld ans = 0;
	lld cont = 1;
	
	for(int i = 1; i < rectas.size(); i++){
		if(ant == rectas[i]){
			cont++;
		}else{
			ans += (cont * (cont - 1)) / 2;
			ant = rectas[i];
			cont = 1;
		}
	}
	ans += (cont * (cont - 1)) / 2;
	pair <lld, pair<lld, pair<lld, lld> > > ant2 = R[0];
	cont = 1;
	
	for(int i = 1; i < R.size(); i++){
		
		if(ant2 == R[i]){
			cont++;
		}else{
			ans -= (cont * (cont - 1)) / 2;
			ant2 = R[i];
			cont = 1;
		}
	}
	ans -= (cont * (cont - 1)) / 2;
	cout << ans / 2 << endl;
	return 0;
}