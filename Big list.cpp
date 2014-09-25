#include <bits/stdc++.h>

using namespace std;

vector <pair <string, string> > P; 

char cadena[100000];

int main(){
   int N, M;
   cin >> N >> M;
   for(int i = 0; i < N; i++){
      string a, b;
      cin >> a >> b;
      P.push_back(make_pair(a, b));
   }
   gets(cadena);
   for(int i = 0; i < M; i++){
      string a, b;
      a = "";
      b = "";
      gets(cadena);
      bool chosto = false;
      bool lol = false;
      for(int j = 0; cadena[j]; j++){
         if(cadena[j] == ' ')
            lol = true;
         else{
            if(lol)
               chosto = true, b += cadena[j];
            else a += cadena[j];
         }
      }
      if(!chosto)
         puts("not found");
      else{
         bool chosto = true;
         for(int i = 0; i < N; i++){
            if(P[i].first == a){
               if(P[i].second == b){
                  puts("ok");
                  break;
               }else{
                  puts("wrong");
                  break;
               }
            }
         }
      }
   }
   return 0;
}
