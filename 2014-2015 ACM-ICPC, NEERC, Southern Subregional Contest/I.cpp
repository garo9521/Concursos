#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector <int>  A;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	int ans = 1;
	int total = A[N - 1];
	for(int i = 0; i < N - 1 && total > 0; i++){
		total -= A[i];
		if(total >= 0)
			ans++;
	}
	cout << ans << endl;
	return 0;
}