#include <bits/stdc++.h>

using namespace std;

vector <int> primos;
int criba[1000];

int main(){
   for(int i = 2; i < 400; i++){
      if(!criba[i]){
         primos.push_back(i);
         for(int j = i * i; j < 400; j += i){
            criba[j] = 1;
         }
      }
   }
   int N;
   cin >> N;
   while(N--){
      int a;
      cin >> a;
      int ans = 0;
      for(int i = 0; i < primos.size(); i++){
         for(int j = i; j < primos.size(); j++){
            if(primos[i] + primos[j] == a)
               ans++;
         }
      }
      cout << ans << endl;
   }
   return 0;
}
