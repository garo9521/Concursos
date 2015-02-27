#include <bits/stdc++.h>

using namespace std;

#define pii pair <int, int>
#define MAXN 1000000

pii A[MAXN];
int ganar[MAXN];

int votosA, votosB;
vector < pii > salida;
int ans;

int main(){
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i].first >> A[i].second;
		if(A[i].first > A[i].second)
			votosA++, ganar[i] = 1;
		if(A[i].first <= A[i].second)
			votosB++, ganar[i] = -1;
	}
	int n = N;
	for(int i = 0; i < N - 1; i++){
		if(votosA * 2 >  n)
			break;
		if(ganar[i] == 1 && ganar[i + 1] == 1)
			continue;
		pii a = make_pair(A[i].first + A[i + 1].first, A[i].second + A[i + 1].second);
		if (a.first > a.second || ganar[i] == -1 && ganar[i + 1] == -1) {
			ans++;
			salida.push_back(make_pair(i + 1, i + 2));
			i++;
			n--;
		}
		
	}
	if(votosA * 2 <= n){
		puts("-1");
		return 0;
	}
	cout << ans << endl;
	for(int i = 0; i < ans; i++)
		cout << salida[i].first << " " << salida[i].second << endl;
	return 0;
}