#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL p[100];

inline void insert(long long x) {
	for (int i = 55; i + 1; i--) {
		if (!(x >> i))  // x的第i位是0
			continue;
		if (!p[i]) {
			p[i] = x;
			break;
		}
		x ^= p[i];
	}
}

void solve() {
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) {
		LL x;
		scanf("%lld", &x);
		insert(x);
	}
	
	
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
