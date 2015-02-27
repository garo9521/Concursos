#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define MAXN 1000005
#define INF (1 << 30)


int main(){
	int N;
	cin >> N;
	lld sum = 0;
	for(int i = 1; i <= N; i++){
		lld a;
		cin >> a;
		lld b = a * i - sum;
		cout << b << " ";
		sum += b;
	}
	return 0;
}