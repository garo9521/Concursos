#include <bits/stdc++.h>
using namespace std;

char board[19][19];

int movs[4][2] = {
	{1, -1},
	{1, 1},
	{-1, 1},
	{-1, -1}
};

bool hayNegra(int x, int y){
	if(x < 0 || x >= 10 || y < 0 || y >= 10) return false;
	if(board[x][y] == 'B') return true;
	return false;
}

bool estaLibre(int x,int y)
{
	if(x < 0 || x >= 10 || y < 0 || y >= 10) return false;
	if(board[x][y] != '#') return false;
	return true;
}

int busca(int x, int y){
	int answer = 0;
	for(int i = 0; i < 4; i++)
	{
		if(hayNegra(x + movs[i][0], y + movs[i][1]) && estaLibre(x + 2*movs[i][0], y + 2*movs[i][1])){
			board[x + movs[i][0]][y + movs[i][1]] = '#';
			int r = busca(x + 2*movs[i][0], y + 2*movs[i][1]);
			board[x + movs[i][0]][y + movs[i][1]] = 'B';
			answer = max(answer, r + 1);
		}
	}
	return answer;
}

int main(){
	int t;
	cin >> t;
	cin.get();
	while(t--){
		cin.getline(board[0], 15);
		for(int i = 0; i <  10; i++)
			cin.getline(board[i], 15);
		
		int answer = 0;
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				if(board[i][j] == 'W'){
					board[i][j] = '#';
					int r = busca(i, j);
					answer = max(answer, r);
					board[i][j] = 'W';					
				}
			}
		}		
		cout << answer << endl;
	}	
	return 0;
}