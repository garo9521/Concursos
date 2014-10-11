#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

int num[MAXN];

int main(){
	int T;
	cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		for(int i= 0; i < N; i++)
			cin >> num[i];
		int maxi = *max_element(num, num + N);
		for(int i = 0; i < N; i++)
			M -= maxi - num[i];
		if(M % N == 0 && M >= 0)
			puts("Yes");
		else puts("No");
	}
	return 0;
}