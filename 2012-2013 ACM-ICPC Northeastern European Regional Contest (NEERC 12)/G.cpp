#include <bits/stdc++.h>

using namespace std;

#define lli long long int

lli k, b;

lli f(lli n) {
	if (n < k) {
		return n + 1;
	}
	lli x = 1, e, a = 1;
	while (x <= n / b) {
		x *= b;
		a *= k;
	}
	e = x * k;
	//a /= k;
	if (n >= e) {
		//cout << "f(" << n << ") = f(" << e - 1 << ")" << endl;
		return f(e - 1);
	}
	//cout << "f(" << n << ") = f(" << n % x << ") + " << (n / x) * a << endl;
	return f(n % x) + (n / x) * a;
}

int main() {
	lli n;
	//freopen("great.in", "r", stdin);
	//freopen("great.out", "w", stdout);
	cin >> n >> k;
	b = k * k;
	cout << f(n) << endl;
	return 0;
}