#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 510, MOD = 1e9 + 7;
int a[N];
LL f[N][N];

void solve() {
	int n, m;
	memset(f, 0, sizeof(f));
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", a + i);
	
	if(n == 1) {
		printf("0\n");
		return;
	} 
	
	for(int i = 1;i <= n;i++) f[i][i] = 1;
	
	for(int i = 1;i <= n - 1;i++) {
		if(abs(a[i]) == abs(a[i + 1]) && a[i] != a[i + 1]) f[i][i + 1] = 1;
		else if(a[i] == 0 && a[i + 1] == 0) f[i][i + 1] = m;
		else if(a[i] == 0 || a[i + 1] == 0) f[i][i + 1] = 1; 
	}
	
	
	for(int len = 3;len <= n;len++) {
		for(int l = 1;l + len - 1 <= n;l++) {
			int r = l + len - 1;
			for(int k = l + 1;k < r;k++) f[l][r] = (f[l][r] + (f[l][k] * f[k + 1][r]) % MOD) % MOD;
			if(abs(a[l]) == abs(a[r]) && a[l] != a[r]) f[l][r] = (f[l][r] + f[l + 1][r - 1]) % MOD;
			else if(a[l] == 0 && a[r] == 0) f[l][r] = (f[l][r] + f[l + 1][r - 1] * m % MOD) % MOD;
			else if(a[l] == 0 || a[r] == 0) f[l][r] = (f[l][r] + f[l + 1][r - 1]) % MOD;
		}
	}
	
	cout << f[1][n] << endl;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
