#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	int ant = -1;
	char ant2 = -1;
	bool chosto = false;
	while(N--){
		int a;
		char c;
		cin >> a >> c;
		if(ant == a || ant2 == c)
			chosto = true;
		ant = a;
		ant2 = c;
	}
	if(chosto)
		puts("M");
	else puts("B");
	return 0;
}