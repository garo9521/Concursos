#include <bits/stdc++.h>
using namespace std;

int n;
int pot[10];
int edo[10];
int ban;

void checa (int pos){
	if (pos > 6){
		int tot = 0;
		for (int i = 0; i <= 6; i++)
			tot += (edo[i] * pot[i]);
		if (tot == n){
			ban = 1;
			int aux = 6;
			while (edo[aux] == 0)
				aux--;
			while (aux >= 0){
				if (edo[aux] == 1)
					printf ("+");
				if (edo[aux] == 0)
					printf ("0");
				if (edo[aux] == -1)
					printf ("-");
				aux--;
			}
			printf ("\n");
		}
	}else{
		if (ban == 0){
			edo[pos] = 1;
			checa (pos + 1);
			edo[pos] = -1;
			checa (pos + 1);
			edo[pos] = 0;
			checa (pos + 1);
		}
	}
}

void proceso (){
	pot[0] = 1;
	for (int i = 1; i <= 6; i++)
		pot[i] = pot[i - 1] * 3;
	scanf ("%d",&n);
	checa (0);
}

int main (){

	proceso ();
	return 0;
}