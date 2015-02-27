#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int game[MAXN];

int main(){
	int N;
	cin >> N;
	for(int i = 2; i <= N; i++){
		if(game[i - 2] == 0)
			game[i] = 1;
		else if(i >= 3 && game[i - 3] == 0)
			game[i] = 1;
		else if(i >= 5 && game[i - 5] == 0)
			game[i] = 1;
		else game[i] = 0;
	}
	if(game[N])
		puts("Alejandra");
	else puts("Nadie");
	return 0;
}