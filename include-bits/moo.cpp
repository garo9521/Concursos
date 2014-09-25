#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

pair <int, int> A[MAXN];

int main(){
   int N;
   cin >> N;
   A[1] = make_pair(3, 3);
   int cont = 2;
   while(A[cont - 1].first <= 1000000000){
      A[cont] = make_pair(A[cont - 1].first * 2 + A[cont - 1].second + 1, A[cont - 1].second + 1);
      
      cont++;
   }
   while(true){
      
      int pos;
      for(int i = cont - 1; i >= 0; i--){
         if(A[i].first < N){
            pos = i + 1;
            break;
         }
      }
      N -= A[pos - 1].first;
      if(N <= A[pos].second){
         if(N == 1){
            puts("m");
         }else{
            puts("o");
         }
         break;
      }else{
         N -= A[pos].second;
         
      }
   }
   return 0;
}
