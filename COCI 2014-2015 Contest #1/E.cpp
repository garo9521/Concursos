#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define MAXN 1000005
#define INF (1 << 30)

int num[MAXN];


int main(){
	lld N, M, K;
	cin >> N >> M >> K;
	lld ans = 0;
	lld sum = 0;
	int k = N / K;
	if(k == 0)
		k = 1;
	for(int i = 0; i < N; i++){
		if(i % K == 0)
			sum = 0;
		sum++;
		ans = max(sum, ans);
		cin >> num[i];
		
	}
	cout << ans << endl;	
	return 0;
}