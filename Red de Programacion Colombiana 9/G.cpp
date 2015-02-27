#include <bits/stdc++.h>

using namespace std;

#define lld long long int
#define MAXN 1000005
#define INF (1 << 30)

int num[MAXN];
vector <int> sobra;


int main(){
	int N;
	cin >> N;
	int A = 0, B = 0;
	for(int i = 0; i < N; i++){
		cin >> num[i];
	}
	
	sort(num, num + N);
	reverse(num, num + N);
	for(int i = 0; i < N; i += 2){
		sobra.push_back(num[i] - num[i + 1]);
		A += num[i];
		B += num[i + 1];
	}
	sort(sobra.begin(), sobra.end());
	
	int ans = -1;
	int pos = 0;
	while(A > B && pos < N / 2){
		ans++;
		A -= sobra[pos];
		B += sobra[pos];
		pos++;
	}
	cout << ans << endl;
	return 0;
}