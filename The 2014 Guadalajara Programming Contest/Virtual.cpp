#include <bits/stdc++.h>

using namespace std;

struct Union{
   int sets;
   int *parent;
   int *members;
   
   void init(int n){

      sets = n;
      parent = new int[n];
      members = new int[n];
      for(int i = 0; i < n; i++){
         parent[i] = i, members[i] = 1;
      }
   }
   
   int find(int a){
      if(a == parent[a]) return a;
      return parent[a] = find(parent[a]);
   }
   int setsize(int a){
      return members[find(a)];
   }
   bool joined(int a, int b){
      return find(a) == find(b);
   }
   void join(int a, int b){
      if(joined(a, b)) return;
      members[find(b)] += members[find(a)];
      parent[find(a)] = find(b);
      sets--;
   }
      
};

map <string, int> mapeo;

int main(){
   int T;
   cin >> T;
   while(T--){
      int N;
      cin >> N;
      Union lol;
      lol.init(N * 2);
      mapeo.clear();
      int cont = 0;
      for(int i = 0; i < N; i++){
         string a, b;
         cin >> a >> b;
         if(mapeo.find(a) == mapeo.end()){
            mapeo[a] = cont;
            cont++;
         }
         
         if(mapeo.find(b) == mapeo.end()){
            mapeo[b] = cont;
            cont++;
         }
         lol.join(mapeo[a], mapeo[b]);
         cout << lol.setsize(mapeo[a]) << endl;
      }
   }
   return 0;
}
