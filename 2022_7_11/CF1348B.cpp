#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	set<int> s;
	for(int i = 0;i < n;i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	
	if(s.size() > k) {
		cout << -1 << endl;
		return;
	}
	
	cout << n * k << endl;
	for(int i = 0;i < n;i++) {
		for(auto e : s) cout << e << " ";
		for(int i = 0;i < k - (int)s.size();i++) cout << 1 << " ";
	}
	cout << endl;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
