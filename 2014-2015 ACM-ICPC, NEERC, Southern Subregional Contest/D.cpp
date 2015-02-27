#include <bits/stdc++.h>
using namespace std;

#define lli long long int

struct S {
	int i, l, u;
	lli c;
};

bool operator<(const S &a, const S &b) {
	if (a.c == b.c)
		return a.l > b.l;
	return a.c > b.c;
}

S a[200003];

int main() {
	int n, i, j, r, w;
	lli t, m;
	S s;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		s.i = i + 1;
		s.u = false;
		cin >> s.c;
		scanf("%d", &s.l);
		a[i] = s;
	}
	sort(a, a + n);
	t = 0;
	w = 0;
	for (i = 0; t < m; i++) {
		t += a[i].c;
		a[i].u = true;
		if (a[i].l) {
			w++;
		}
	}
	r = i;
	j = i - 1;
	for (; i < n; i++) {
		if (a[i].l) {
			for (; j >= 0; j--) {
				if (!a[j].l) {
					if (t + a[i].c - a[j].c >= m) {
						a[i].u = true;
						a[j].u = false;
						t += a[i].c - a[j].c;
						w++;
						j--;
						break;
					} else {
						i = n;
					}
				}
			}
			if (j < 0) {
				i = n;
			}
		}
	}
	printf("%d %d\n", r, w);
	for (i = j = 0; i < n && j < r; i++) {
		if (a[i].u) {
			printf("%d", a[i].i);
			j++;
		}
		if (j != r) {
			printf(" ");
		}
	}
	return 0;
}