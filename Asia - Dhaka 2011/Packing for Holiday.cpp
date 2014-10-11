#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cout << "Case " << i << ": ";
		int a, b, c;
		cin >> a >> b >> c;
		if(max(a, max(b, c)) > 20)
			puts("bad");
		else puts("good");
	}
	return 0;
}