#include <bits/stdc++.h>

using namespace std;

#define lld long long int

lld busca(lld a, lld b){
   if(a & 1 && b & 1)
      return busca(a / 2, b / 2) * 4 + 1;
   return 0;
}

int main(){
   lld N, M;
   cin >> N >> M;
   cout << busca(N, M) << endl;
   return 0;
}
