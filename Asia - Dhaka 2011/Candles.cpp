#include <bits/stdc++.h>

using namespace std;

int mask[1 << 11][101];
bool precal[1 << 11][101];
vector <int> num;

int K;

void busca(int num, int usados){
	if(num > 100)
		return;
	if(precal[K][num])
		return;
	mask[K][num] = usados;
	precal[K][num] = 1;
	cout << num << " ";
	for(int i = 0; i <= 5; i++){
		if(!((1 << i) & usados) && K & (1 << i)){
			busca(num * 10 + i, usados ^ (1 << i));
		}
	}
}

int main(){
	for(int i = 1; i < (1 << 5); i++){
		K = i;
		busca(0, 0);
		cout << i << endl;
		for(int k = 0; k < 101; k++){
			for(int j = 0; j < 101; j++){
				if(!(mask[i][k] & mask[i][j]) && precal[i][k] && precal[i][j] && j + k <= 100){
					cout << k + j << " ";
					precal[i][k + j] = 1;
				}
			}
		}
		puts("");
	}
	int N;
	int caso = 1;
	while(true){
		cin >> N;
		if(N == 0)
			break;
		cout << "Case " << caso++ << ": ";
		num.clear();
		for(int i = 0; i < N; i++){
			int a;
			cin >> a;
			num.push_back(a);
		}
		for(int i = 1; i < (1 << 11); i++){
			bool chosto = true;
			for(int k = 0; k < N; k++){
				if(!precal[i][num[k]]){
					chosto = false;
					break;
				}
			}
			if(chosto){
				for(int j = 9; j >= 0; j--){
					if(i & (1 << j)){
						cout << j;
					}
				}
				
				puts("");
				break;
			}
		}
		
	}
	return 0;
}