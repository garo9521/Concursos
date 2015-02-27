#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000005

map <long long int , long long int> A;
int num[MAXN];

int numberLetters(char x){
	if(x >= 'a' && x <= 'z')
		return x - 'a';
	return x - 'A' + 'z' - 'a' + 1;
}

int main(){
	freopen("hyperdrome.in", "r", stdin);
	freopen("hyperdrome.out", "w", stdout);
	int N;
	string cadena;
	cin >> N >> cadena;
	for(int i = 0; i < N; i++)
		num[i] = numberLetters(cadena[i]);
	A[0]++;
	long long int mask = 0;
	long long int ans = 0;
	for(int i = 0; i < N; i++){
		mask ^= (1ll << num[i]);
		if(A.find(mask) != A.end())
			ans += A[mask];
		for(int j = 0; j < ('z' - 'a' + 1) * 2; j++){
			mask ^= 1ll << j;
			if(A.find(mask) != A.end())
				ans += A[mask];
			mask ^= 1ll << j;
		}
		A[mask]++;
	}
	cout << ans << endl;
	return 0;
}