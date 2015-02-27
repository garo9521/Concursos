#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

int num[MAXN];


int main(){
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> num[i];
	int sum = 0;
	int ans = -1;
	for(int i = 0; i < M * 2 ; i++)
		sum += num[i];
	ans = max(ans, sum);
	for(int i = M * 2; i < N; i++){
		sum += num[i];
		sum -= num[i - M * 2];
		ans = max(ans, sum);
	}
	int ant = 0;
	for(int i = 0; i < M; i++)
		ant += num[i];
	int sum2 = ant;
	sum = 0;
	for(int i = M; i < M * 2; i++)
		sum += num[i];
	ans = max(ans, sum + ant);
	for(int i = M * 2; i < N; i++){
		sum += num[i];
		sum -= num[i - M];
		sum2 += num[i - M];
		sum2 -= num[i - M * 2];
		ant = max(ant, sum2);
		ans = max(ans, ant + sum);
	}
	cout << ans << endl;
	return 0;
}