#include <bits/stdc++.h>

using namespace std;

int cubeta[1000];

int main(){
   int N;
   cin >> N;
   while(N--){
      string a;
      cin >> a;
      for(int i = 0; i < a.size(); i++){
         cubeta[a[i]]++;
      }
      if(cubeta['B'] == cubeta['R'] && cubeta['R'] == cubeta['O'] && cubeta['O'] == cubeta['K'] &&cubeta['K'] == cubeta['E'] && cubeta['E'] == cubeta['N'])
         puts("No Secure");
      else puts("Secure");
      for(int i = 0; i < 1000; i++)
         cubeta[i] = 0;
   }
   return 0;
}
