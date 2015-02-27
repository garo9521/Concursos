#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define MAXN 1000005
#define INF (1 << 30)

int BIT[MAXN];
pair <int, int> lineas[MAXN];
int N;


void update(int i, int x){
	for(; i <= N; i += i & -i)
		BIT[i] += x;
}

int query(int i){
	int sum = 0;
	for(; i ; i -= i & -i)
		sum += BIT[i];
	return sum;
}

int main(){
	cin >> N;
	int ans = 0;
	for(int i = 1; i <= N; i++){
		int a;
		cin >> a;
		if(query(a) == 0)
			ans++;
		update(a, 1);
	}
	cout << ans << endl;
	return 0;
}