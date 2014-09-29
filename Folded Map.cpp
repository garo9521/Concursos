#include <bits/stdc++.h>
using namespace std;

#define MARGEN 110

int n, m, a, b, mapa[1500][1500], aux[1500][1500], i, j, k, l, mans, ans;
char c;

int main()
{
    while(scanf("%d%d%d%d", &n, &m, &a, &b) != EOF) {
        getchar();
        for (i = 0; i < n + MARGEN + MARGEN; i++) {
            for (j = 0; j < m + MARGEN + MARGEN; j++) {
                mapa[i][j] = 0;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                mapa[i + MARGEN][j + MARGEN] = getchar() == '.' ? 0 : 1;
            }
            getchar();
        }
        for (i = 0; i < n + MARGEN; i++) {
            for (j = 0; j < m + MARGEN; j++) {
                mapa[i + MARGEN][j + MARGEN] += mapa[i + MARGEN - 1][j + MARGEN];
            }
        }
        for (i = 0; i < n + MARGEN; i++) {
            for (j = 0; j < m + MARGEN; j++) {
                mapa[i + MARGEN][j + MARGEN] += mapa[i + MARGEN][j + MARGEN - 1];
            }
        }
        mans = 1 << 30;
        for (i = MARGEN - a; i < MARGEN; i++) {
            for (j = MARGEN - b; j < MARGEN; j++) {
                ans = 0;
                for (k = i; k < n + MARGEN + MARGEN; k += a) {
                    for (l = j; l < m + MARGEN + MARGEN; l += b) {
                        ans += mapa[k][l] - mapa[k - a][l] - mapa[k][l - b] + mapa[k - a][l - b] > 0 ? 1 : 0;
                    }
                }
                mans = min(mans, ans);
            }
        }
        printf("%d\n", mans);
    }
    return 0;
}
