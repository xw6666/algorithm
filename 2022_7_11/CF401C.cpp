#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,m;
	cin >> n >> m;
	if(n == 1) {
		if(m >= 1 && m <= 4) {
			while(m || n) {
				if(m) {
					if(m >= 2) cout << "11", m -= 2;
					else cout << "1", m --;
				}
				if(n) cout << "0", n--;
			}
			cout << endl;
		} else cout << -1 << endl;
	} else {
		if(m >= n - 1 && m <= n * 2 + 2) {
			if(m >= n - 1 && m <= n) {
				while(m || n) {
					if(n) cout << "0", n--;
					if(m) cout << '1', m--;
				}
				cout << endl;
			}
			else {
				int k = m - n;
				while(k--) {
					if(m >= 2) cout << "11", m -= 2;
					if(n) cout << "0", n--;
				}
				
				while(m || n) {
					if(m) cout << '1', m--;
					if(n) cout << '0', n--;
				}
				
				cout << endl;
			}
		} else cout << -1 << endl;
	}
}

int main() {

	solve();
	
	return 0;
}
