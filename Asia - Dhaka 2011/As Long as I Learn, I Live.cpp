#include <bits/stdc++.h>
using namespace std;
 
int t;
int n, m;
int num[102];
int mayor[102];
 
void proceso (){
	scanf ("%d",&t);
	for (int casos = 1; casos <= t; casos++){
		scanf ("%d",&n);
		scanf ("%d",&m);		
		for (int i = 0; i < n; i++)	
			scanf ("%d",&num[i]);
		for (int i = 1; i <= m; i++){
			int a, b;
			scanf ("%d",&a);		
			scanf ("%d",&b);		
			if (num[mayor[a]] < num[b])
				mayor[a] = b;		
		}
		int pos = 0;
		int res = 0;
		while (mayor[pos] > 0){
			res += num[mayor[pos]];
			pos = mayor[pos];			
		}
		for (int i = 0; i < n; i++)
			mayor[i] = 0;
		printf ("Case %d: %d %d\n", casos, res + num[0], pos);
	}
}
 
int main (){
 
	proceso ();
	return 0;
}