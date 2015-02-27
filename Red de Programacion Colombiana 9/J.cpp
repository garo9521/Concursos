#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define MAXN 1000005
#define INF (1 << 30)

int num[MAXN];
bitset <MAXN> can;

int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> num[i];
	can[N] = 1;
	for(int i = N - 1; i >= 0; i--){
		if(can[i + num[i] + 1])
			can[i] = 1;
		else can[i] = 0;
	}
	for(int i = 1; i <= N; i++)
		if(can[i])
			cout << i << endl;
	
	return 0;
}