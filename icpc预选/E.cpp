#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first 
#define y second  

void solve() {
	int n, k;
	cin >> n >> k;
	LL ans = 0;
	if(k % 2) {
		ans += k;
		if((n - 1) % 2)
		{
			ans += (n - 1) / 2 * 3 + ((n - 1) / 2 + 1) * 2;
		}
		else
		{
			ans += (n - 1) / 2 * 3 + (n - 1) / 2 * 2;
		}
	}
	else
	{
		int cnt = 3;
		while(1)
		{
			if(k % cnt) break;
			cnt += 2;
		}
		ans += k + cnt;
		if((n - 2) % 2)
		{
			ans += (n - 2) / 2 * 3 + ((n - 2) / 2 + 1) * 2;
		}
		else
		{
			ans += (n - 2) / 2 * 3 + (n - 2) / 2 * 2;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
//	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
