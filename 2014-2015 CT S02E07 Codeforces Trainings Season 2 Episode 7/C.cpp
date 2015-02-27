#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int N;
	cin >> N;
	if((N & (N - 1)) == 0)
		puts("TAK");
	else puts("NIE");
	return 0;
}