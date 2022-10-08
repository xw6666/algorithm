#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int s[N];
int n, power, k;

void solve() {
	cin >> n >> power >> k;
	int sum = 0;
	for(int i = 1;i <= n;i++) scanf("%d", a + i), sum += a[i];
	
	for(int i = 1;i <= n;i++) {
		if(a[i] <= power) power += a[i];
		else {
			for(int j = i + k;j > i;j--) {
				int cur = j;
				int cp = power;
				bool flag = true;
				while(cur >= i) {
					if(a[i] <= cp) {
						cur--;
						cp += a[i];
					} else {
						flag = false;
						break;
					}
				}
				
				if(flag) {
					power = cp;
					break;
				}
			}
		}
	}
	if(power == sum) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
