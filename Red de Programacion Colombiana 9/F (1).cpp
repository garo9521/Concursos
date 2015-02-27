#include <bits/stdc++.h>
#define INF 1000005
#define pii pair<int,int>
#define psi pair<string,pii>
#define MOD 1000000007
#define lli long long int

using namespace std;

struct ura{
	int posicion,id;
	char ultimo;
};

char cade[105][10005];
ura cad[105];
char aux[105];

bool operator < (ura a,ura b){
	if(a.ultimo!=b.ultimo)
		return a.ultimo<b.ultimo;
	return a.id<b.id;
}

void borrar(int a,int n){
	for(int i=0;i<n;i++){
		cad[i].posicion-=a;
		cad[i].posicion=max(cad[i].posicion,0);
		cade[cad[i].id][cad[i].posicion]='\0';
		if(cad[i].posicion-1>=0)
			cad[i].ultimo=cade[cad[i].id][cad[i].posicion-1];
		else
			cad[i].ultimo='.';
	}
	sort(cad,cad+n);
}

void add(int n){
	for(int i=0;i<n;i++){
		cade[cad[i].id][cad[i].posicion]=aux[i];
		cad[i].ultimo=aux[i];
		cad[i].posicion++;
		cade[cad[i].id][cad[i].posicion]='\0';
	}
	sort(cad,cad+n);
}

int main(){
	int n,q,a,pos;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		strcpy(cade[i],"");
		cad[i].posicion=0;
		cad[i].id=i+1;
		cad[i].ultimo='.';
	}
	while(q--){
		scanf("%d %s %d",&a,aux,&pos);
		borrar(a,n);
		add(n);
		printf("%d\n",cad[pos-1].id);
	}
	return 0;
}