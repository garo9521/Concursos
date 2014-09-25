#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

char cadena[MAXN];
int maxi[2];

int main(){
   int N;
   scanf("%d", &N);
   for(int i = 0; i < N; i++){
      scanf("%s", cadena);
      int jugador = 0;
      maxi[0] = maxi[1] = 0;
      int cont = 0;
      for(int j = 0; cadena[j]; j++){
         if(j != 0 && (cadena[j - 1] == ')' && cadena[j] == ':')){
            maxi[jugador] = max(maxi[jugador], cont);
            jugador ^= 1;
            cont = 0;
         }
         cont++;
      }
      maxi[jugador] = max(maxi[jugador], cont);
      if(maxi[0] > maxi[1])
         puts("Jennifer");
      else puts("Alan");
   }
   return 0;
}
