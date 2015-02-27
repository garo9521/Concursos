#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
#define lli long long int

int N;
pair <lli, lli> segment[MAXN];

bool menorQue(pair <lli, lli> a, pair <lli, lli> b){
	if(a.first * b.second < b.first * a.second)
		return true;
	return false;
}

bool checa(double x){
	double ant = segment[0].first + x;
	if(segment[0].second < ant)
		return false;
	for(int i = 1; i < N; i++){
		double now;
		if(segment[i].first  <= ant)
			now = ant;
		else now = segment[i].first ;
		now += x;
		if(now > segment[i].second)
			return false;
		ant = now;
	}
	return true;
}

int ans(double x, double b){
	long long int ini = 0, fin = 10000000000ll;
	long long int medio;
	while(ini <= fin){
		medio = (ini + fin) / 2;
		if((double)(medio) / b == x)
			return medio;
		if((double)(medio) / b > x)
			fin = medio - 1;
		else ini = medio + 1;
	}
	return 0;
}

int main(){
	//freopen("caravan.in", "r", stdin);
	//freopen("caravan.out", "w", stdout);
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> segment[i].first >> segment[i].second;
	sort(segment, segment + N);
	double ini, fin, medio;
	ini = 0.0;
	fin = 1000000.0;
	for(int i = 0; i < 300; i++){
		/*medio = make_pair(ini.first * fin.second + fin.first * ini.second, ini.second * fin.second * 2ll);
		lli mcd = __gcd(medio.first, medio.second);
		medio.first /= mcd;
		medio.second /= mcd;
		*/
		medio = (ini + fin) / 2.0;
		if(checa(medio)){
			ini = medio;
		}else{
			fin = medio;
		}
	}
	long long int A = (long long int)(ini);
	double aux = ini - A;
	long long int B = 0;
	long long int C = 1;
	while(aux > 0.0000000000000000000000){
		aux *= 10.0;
		long long int a = (long long int)(aux);
		B = B * 10 + a;
		aux -= a;
		C *= 10;
	}
	long long int a = A * C + B;
	long long int b = C;
	long long int mcd = __gcd(a, b);
	a /= mcd;
	b /= mcd;
	while(ini != ((double)(a)) / ((double)(b))){
		b++;
		long long int mcd = __gcd(a, b);
		a /= mcd;
		b /= mcd;
	}
	int rq = 0;
  double min_diff = 1e100;
  double l = ini;
  for (int q = 1; q <= N; q++)
  {
    double pr = l * q;
    int val = (int)(pr + 0.5);
    double diff = fabs(pr - val) / q;
    if (diff < min_diff)
      min_diff = diff, rq = q;
  }

  int rp = (int)(l * rq + 0.5);
  int g = __gcd(rp, rq);
  printf("%d/%d\n", rp / g, rq / g);
	return 0;
}