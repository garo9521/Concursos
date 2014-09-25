#include <bits/stdc++.h>

using namespace std;

map <long long int, long long int> lol; 

int main(){
   int T;
   
   cin >> T;
   while(T--){
      int N;
      cin >> N;
      long long int ans = 0;
      lol.clear();
      lol[0] = 1;
      long long int sum = 0;
      
      for(int i = 0; i < N; i++){
         int a;
         cin >> a;
         
         sum += num[i];
         if(lol.find(sum - 47) != lol.end())
            ans += lol[sum - 47];
         lol[sum]++;
      }
      cout << ans << endl;
   }
   return 0;
}
