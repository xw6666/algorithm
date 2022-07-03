#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
const int N = 200;
int a[N];

void solve() {
	unordered_set<int> s;
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0;i < n;i++) {
		scanf("%d", a + i);
		ans ^= a[i];
		s.insert(a[i]);
	}
	
	int idx = -1;
	for(int i = 0;i < n;i++) {
		if(s.find(ans ^ a[i]) != s.end()) {
			idx = i;
			break;
		}
	}
	
	printf("%d\n", a[idx]);
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	
	return 0;
}
