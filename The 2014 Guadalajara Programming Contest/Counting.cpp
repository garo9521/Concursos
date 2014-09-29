#include <bits/stdc++.h>

using namespace std;

map <long long int, long long int> cubeta; 

int main(){
   int T;
   
   cin >> T;
   while(T--){
      int N;
      cin >> N;
      long long int ans = 0;
      cubeta.clear();
      cubeta[0] = 1;
      long long int sum = 0;
      
      for(int i = 0; i < N; i++){
         int a;
         cin >> a;
         
         sum += num[i];
         if(cubeta.find(sum - 47) != cubeta.end())
            ans += cubeta[sum - 47];
         cubeta[sum]++;
      }
      cout << ans << endl;
   }
   return 0;
}
