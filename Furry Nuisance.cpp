#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005

vector <int> aristas[MAXN];
vector <int> degree;
bool cubeta[MAXN];

struct Union{
    int sets;
    int* parent;
    int* members;

    void init(int n){
        sets = n;
        parent = new int[n];
        members = new int[n];
        for(int i = 0; i < n; i++)
            parent[i] = i, members[i] = 1;
    }

    int find(int a){
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }

    int setSize(int a){
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

int main(){
    int N, M;
    while(scanf("%d%d", &N, &M) != EOF){
        for(int i = 0; i <= N; i++)
            aristas[i].clear();
        degree.clear();
        Union grafo;
        grafo.init(N);
        bool chosto = false;
        bool can = false;
        for(int i = 0; i < M; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            grafo.join(a - 1, b - 1);
            aristas[a].push_back(b);
            aristas[b].push_back(a);
            if(aristas[a].size() > 3)
                chosto = true;
            if(aristas[b].size() > 3)
                chosto = true;
        }
        if(chosto)
            puts("YES");
        else{
			for(int i = 0; i < degree.size() && !chosto; i++){
				for(int j = i + 1; j < degree.size() && !chosto; j++){
					int a = degree[i];
					int b = degree[j];
					if(!grafo.joined(a - 1, b - 1))
						continue;
						
					int cont = 0;
					cubeta[a] = true;
					for(int k = 0; k < 3; k++)
						cubeta[aristas[a][k]] = 1;

					for(int k = 0; k < 3; k++)
						if(cubeta[aristas[b][k]])
							cont++;
							
					cubeta[a] = false;
					for(int k = 0; k < 3; k++)
						cubeta[aristas[a][k]] = false;
					
					if(cont < 2)
						chosto = true;
				}
			}
			if(chosto)
				puts("YES");
			else puts("NO");
		}
    }
    return 0;
}
