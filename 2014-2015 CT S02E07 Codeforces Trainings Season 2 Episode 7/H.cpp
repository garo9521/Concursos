#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000005

long double A, B;
long long int ans[MAXN];

int main(){
	int N;
	cin >> N;
	getchar();
	long long int x = 0;
	long long int acarreo = 0;
	long long int now;
	for(int i = 0; i < N; i++){
		char c;
		cin >> c;
		
		now = acarreo + x;
		acarreo = now / 2;
		ans[i] = now;
		if(c == 'H'){
			x++;
		}else{
			x--;
		}
		
	}
	int pos;
	for(pos = N; pos >=0 && ans[pos] == 0; pos--);
	if(pos == -1)
		puts("HM");
	else if(ans[pos] > 0)
		puts("H");
	else puts("M");
	return 0;
}