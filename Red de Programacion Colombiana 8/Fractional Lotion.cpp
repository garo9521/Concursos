#include <bits/stdc++.h>

using namespace std;

char cadena[10000];

map <string, int> answer;

int main() {
    int N;
    for(N = 1; N < 10001; N++){
        int x = 1, y = 1;
        int xx, yy;
        int dif = 0, dif2 = 0;
        int ans = 0;

            int r1, r2, r3, r4;
        while(dif2 >= dif){
            r1 = (x + y) * N;
            r2 = x * y;
            dif = r1 - r2;
            int xx = x, yy = y + 1;

            r3 = (xx + yy) * N;
            r4 = xx * yy;
            dif2 = r3 - r4;
            if(dif2 >= dif){
                x = x + 1;
                y = x;
            }

        }
        while(dif >= 0){
            if(dif % (dif2 - dif) == 0)
                ans++;
            x++;
            y = x;
            r1 = (x + y) * N;
            r2 = x * y;
            dif = r1 - r2;
            int xx = x, yy = y + 1;
            int r3, r4;
            r3 = (xx + yy) * N;
            r4 = xx * yy;
            dif2 = r3 - r4;
        }
        string c = "";
        int a = N;
        while(a){
            c += (char)((a % 10) + '0');
            a /= 10;
        }
        c += "/1";
        reverse(c.begin(), c.end());
        answer[c] = ans;
        ans = 0;
    }
	
    string a;
    while(cin >> a)
        printf("%d\n", answer[a] );
    
	return 0;
}
