#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int a[N];
unordered_map<int,int> m1, m2;

int main() {
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) {
		int x;
		scanf("%d", &x);
		m1.insert({x, i});
	}
	
	for(int i = 0;i < n;i++) {
		int x;
		scanf("%d", &x);
		m2.insert({x, i});
	}
	
	for(auto& e : m1) {
		a[(e.second - m2[e.first] + n) % n] ++;
	}
	
	int ans = 0;
	for(int i = 0;i < n;i++) ans = max(ans, a[i]);
	
	cout << ans << endl;
	
	return 0;
}
