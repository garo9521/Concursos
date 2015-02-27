#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define MAXN 1000005
#define INF (1 << 30)

int num[MAXN];

int main(){
	int N;
	cin >> N;
	int A = 0, B = 0;
	for(int i = 0; i < N; i++){
		cin >> num[i];
		if(i & 1)
			B += num[i];
		else A += num[i];
	}
	int ans = 0;
	int pos = 0;
	while(A > B && pos < N){
		A -= num[pos];
		B -= num[pos + 1];
		A += num[pos + 1];
		B += num[pos];
		pos += 2;
		ans++;
	}
	if(ans)
		cout << ans << endl;
	cout << -1 << endl;
	return 0;
}