#include <bits/stdc++.h>
using namespace std;

struct dato{
	int id;
	int pot;
	long long int val;
};
long long int x, comodin;
int n;
dato num[1000002];
priority_queue <pair< long long int, int> > monti;
long long int diez[20];
int cont;
int apunt;
vector <int> res;

bool pp(dato a, dato b){
	return a.pot < b.pot;
}

void proceso (){
	while(cin >> x >> n){
	for (int i = 1; i <= n; i++){
		cin >> num[i].pot >> num[i].val;
		for(int j = 0; j < num[i].pot; j++)
			num[i].val *= 10;
		num[i].id = i;
	}
	sort (num + 1, num + 1 + n, pp);
	while(!monti.empty()) monti.pop();
	
	int ban = 0;
	int pos = 1;
	int cual = 0;
	long long int comodin = 0;
	long long int pot10 = 10;
	bool can = true;
	while (x > 0 && can){
		for(; pos <= n; pos++){
			if(cual != num[pos].pot)
				break;
			monti.push(make_pair(num[pos].val, num[pos].id));
		}
		long long int necesito = x % pot10;
		while(necesito > comodin){
			pair<long long int, int> saca;
			if(monti.empty()){
				can = false;
				break;
			}
			saca = monti.top();
			monti.pop();
			comodin += saca.first;
			res.push_back(saca.second);
		}
		x -= necesito;
		comodin -= necesito;
		cual++;
		pot10 *= 10;
	}
	sort(res.begin(), res.end());
	if(can){
		cout << res.size() << endl;
		for(int i = 0; i < res.size(); i++){
			if(i !=0)
				cout << " ";
			cout << res[i];
		}
		cout << endl;
	}else{
		cout << -1 << endl;
	}
	res.clear();
	}
}

int main (){
	//freopen("exact.in", "r", stdin);
	//freopen("exact.out", "w", stdout);
	proceso ();
	return 0;
}