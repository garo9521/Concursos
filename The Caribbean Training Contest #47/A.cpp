#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

set <string> vis;

char cadena[MAXN];
string palabras[MAXN];

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		vis.clear();
		getchar();
		gets(cadena);
		int N = 0;
		palabras[0] = "";
		for(int i = 0; cadena[i]; i++){
			if(cadena[i] == ' '){
				N++;
				palabras[N] = "";
			}else{
				palabras[N] += cadena[i];
			}
		}
		while(true){
			string a, b, c;
			cin >> a >> b >> c;
			if(a == "what" && b == "does" && c == "the"){
				cin >> a >> b;
				break;
			}
			vis.insert(c);
		}
		string ans = "";
		for(int i = 0; i <= N; i++)
			if(vis.find(palabras[i]) == vis.end())
				ans += palabras[i] + " ";
		for(int i = 0; i < ans.size() - 1; i++)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}