#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;

const int N = 2e5 + 10;
int a[N];

void solve() {
	int ans = 0;
	int n,k;
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++) {
		scanf("%d", a + i);
	}
	
	for(int i = 1;i < n - 1;i++) {
		if(a[i] > a[i + 1] + a[i - 1]) ans++;
	}
	
	if(k == 1) printf("%d\n", max(ans, (n - 1) / 2));
	else printf("%d\n", ans);
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
