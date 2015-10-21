#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string.h>
#define lli long long int

using namespace std;

double num[300005];
vector<int> color;
int k=3;
int memo[50][5][5];

lli total(int pos,int prev,int f){
	if(pos==29){
		lli res2=0;
		for(int i=0;i<k;i++)
			if(i!=f)
				res2++;
		return res2;
	}
	if(memo[pos][prev][f]!=-1) 
		return memo[pos][prev][f];
	lli res=0;
	for(int i=0;i<k;i++){
		if(pos==0)
			res+=total(pos+1,i,i);
		else if(i!=prev)
			res+=total(pos+1,i,f);
	}
	return memo[pos][prev][f]=res;
}

int main(){
	memset(memo,-1,sizeof memo);
	printf("%lld\n",total(0,0,0));
	return 0;
}
