#include <bits/stdc++.h>

using namespace std;

double F(double a, double b, double c, double d){
   return sqrt((a - c) * (a - c) + (b - d) * (b - d) );
}


int main(){
   int N;
   while(true){
      cin >> N;
      if(N == 0)
         break;
      int x, y;
      cin >> x >> y;
      double ans = 987654321;
      int answer = 0;
      for(int i = 0; i < N; i++){
         int a, b, c;
         cin >> a >> b >> c;
         double dist = F(x, y, a, b) - c;
         if(dist < ans)
         {
            ans = dist;
            answer = i + 1;
         }
      }
      cout << answer << endl;
   }
   return 0;
}
