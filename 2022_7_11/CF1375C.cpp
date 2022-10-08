#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int a,b;
	for(int i = 0;i < n;i++) {
		if(i == 0) scanf("%d", &a);
		else if(i == n - 1) scanf("%d", &b);
		else {
			int x;
			scanf("%d", &x);
		}
	}
	
	if(a < b) printf("YES\n");
	else printf("NO\n");
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
