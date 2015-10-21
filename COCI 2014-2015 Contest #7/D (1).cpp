#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>
#define lli long long int

using namespace std;

lli res[10]={0,2,0,2,2,0,0,0,2};
lli res2[10]={0,49152,96,24,24576,12,3,96,1073741826};

lli fact(long long int n,long long int m){
	return (n*(n-1)*(n-2))/6;
}

int main(){
	long long int n,m;
	cin>>n>>m;
	if(m==1){
		cout<<"0"<<endl;
		return 0;
	}
	long long int ans = 0;
	
	ans += res[n] * ((m * (m - 1)) / 2);
	if(m==2){
		cout<<ans<<endl;
		return 0;
	}
	ans *= 2;
	ans += res2[n] * fact(m, 3);
	cout<<ans<<endl;
	return 0;
}
