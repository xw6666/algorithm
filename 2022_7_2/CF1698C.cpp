#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 2e5 + 10;

void solve() {
	int n;
	cin >> n;
	vector<int> zz, ff, a;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x > 0) {zz.push_back(x);}
		else if (x < 0) {ff.push_back(x);}
		else {
			if (a.size() < 2) {a.push_back(x);}
		}
	}
	if (zz.size() > 2 || ff.size() > 2) {cout << "NO\n"; return;}
	
	for (int i : zz){
		a.push_back(i);
	}
	for (int i : ff){
		a.push_back(i);
	}
	for (int i = 0; i < a.size(); i++) {
		for (int j = i + 1; j < a.size(); j++) {
			for (int k = j + 1; k < a.size(); k++) {
				bool flag = false;
				for (int l = 0; l < a.size(); l++) {
					if (a[i] + a[j] + a[k] == a[l]) {flag = true;}
				}
				if (!flag) {cout << "NO\n"; return;}
			}
		}
	}
	
	cout << "YES" << '\n';
	
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
