#include <bits/stdc++.h>

using namespace std;

#define MAXN 200001

vector <pair<int, long long int> > aristas[MAXN];

long long int f(int a, int padre) {
    long long int suma = 0;
    bool chosto = false;
    for (int i = 0; i < aristas[a].size(); i++)
        if(padre != aristas[a][i].first) {
            suma += min(f(aristas[a][i].first, a), aristas[a][i].second);
            chosto = true;
        }
    if (!chosto)
        return 1 << 20;
    return suma;
}

int main() {
    int i, j, a, b, c, n, r;
    while (scanf("%d%d", &n, &r) != EOF) {
            for(i = 0; i <= n; i++)
                aristas[i].clear();

            for (i = 1; i < n; i++) {
                scanf("%d%d%d", &a, &b, &c);
                aristas[a].push_back(make_pair(b, c));
                aristas[b].push_back(make_pair(a, c));
            }
            printf("%lld\n", f(r, -1));
    }
	return 0;
}
