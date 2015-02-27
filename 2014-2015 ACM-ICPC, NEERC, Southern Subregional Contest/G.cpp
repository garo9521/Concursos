#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005
#define lli long long int

lli A[MAXN];
set <int> disponibles;
set <int> :: iterator it, aux;
lli ans;


int main(){
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> A[i];
	lli tope = *min_element(A, A + N);
	for(int i = 0; i < N; i++){
		if(A[i] != tope){
			disponibles.insert(i);
		}
	}
	lli sum = 0;
	for(int i = 0; i < M; i++)
		sum += A[i];
	
	for(int i = M; i < N; i++){
		if(sum >= 0){
			lli a = sum + 1;
			it = disponibles.lower_bound(i);
			it--;
			ans += a;
			while(a > 0){
				A[*it] -= a;
				if(A[*it] <= tope){
					A[*it] += a;
					sum += tope - A[*it];
					a += tope - A[*it];
					A[*it] = tope;
					aux = it;
					it--;
					disponibles.erase(aux);
				}else{
					sum -= a;
					a = 0;
				}
			}
		}
		sum += A[i];
		sum -= A[i - M];
	}
	if(sum >= 0){
		lli a = sum + 1;
		it = disponibles.lower_bound(N);
		it--;
		ans += a;
		while(a > 0){
			A[*it] -= a;
			if(A[*it] <= tope){
				A[*it] += a;
				sum += tope - A[*it];
				a += tope - A[*it];
				A[*it] = tope;
				aux = it;
				it--;
				disponibles.erase(aux);
			}else{
				sum -= a;
				a = 0;
			}
		}
	}
	
	cout << ans << endl;
	for(int i = 0; i < N; i++)
		cout << A[i] << " ";
	return 0;
}