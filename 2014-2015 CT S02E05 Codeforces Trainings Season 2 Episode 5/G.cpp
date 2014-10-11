#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	cin >> N;
	while(N--){
		string a;
		cin >> a;
		int ult = a.size() - 1;
		if(a[ult] == 'x' ||a[ult] == 's' ||a[ult] == 'o' || (a[ult - 1] == 'c' && a[ult] == 'h'))
			cout << a + "es" << endl;
		else if(a[ult] == 'f'){
			a.pop_back();
			cout << a + "ves" << endl;
		}else if(a[ult - 1] == 'f' && a[ult] == 'e'){
			a.pop_back();
			a.pop_back();
			cout << a + "ves" << endl;
		}else if(a[ult] == 'y'){
			a.pop_back();
			cout << a + "ies" << endl;
		}else cout << a + "s" << endl;
	}
	return 0;
}