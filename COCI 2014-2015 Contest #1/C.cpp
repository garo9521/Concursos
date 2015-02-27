#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define MAXN 1000005
#define INF (1 << 30)

char cadena[MAXN];
vector <int> letters[100];
lld cubeta[100];


int main(){
	lld N;
	cin >> N >> cadena;
	lld M = strlen(cadena);
	for(int i = 0; i < 2 * M; i++){
		letters[cadena[i % M] - 'A'].push_back(i);
		if(i < M)
			cubeta[cadena[i % M] - 'A']++;
	}
	int Q;
	cin >> Q;
	while(Q--){
		lld a;
		char c;
		cin >> a >> c;
		c -= 'A';
		lld ans = a / M;
		int tam = a % M;
		ans *= cubeta[c];
		lld pos;
		if(a & 1){
			pos = ((a % M) * (((a - 1) / 2) % M)) % M;
		}else{
			pos = (((a / 2) % M) * ((a - 1) % M) ) % M;
		}
		
		lld ini = lower_bound(letters[c].begin(), letters[c].end(), pos) - letters[c].begin();
		lld fin = lower_bound(letters[c].begin(), letters[c].end(), pos + tam) - letters[c].begin();
		
		ans += fin - ini;
		cout << ans << endl;
		
		
	}
	return 0;
}