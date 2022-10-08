#include <bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<int, int> PII;
#define x first 
#define y second  

const int N = 110;
int a[N];
int n;

void solve() {
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];

	int cnt = n;
	int sz = n;
	while(cnt--) 
	{
		if(sz <= 4) 
		{
			int ans = (a[sz - 1] - a[0]) * (a[sz - 1] - a[0]);
			cout << ans << endl;
		} 
		else 
		{
			int t = -1;
			int ll = -1, rr = -1;
			int k = 0;
			for(int i = 1;i + 2 < sz - 1;i++) {
				int l = i, r = i + 2;
				int tt = a[l];
				a[l] = a[l - 1];
				int tag = l + 1;
				int ans = 0;
				for(int j = 1;j < sz;j++) {
					if(j == tag) continue;
					if(j == tag + 1)  ans += (a[j] - a[j - 2]) * (a[j] - a[j - 2]);
					else ans += (a[j] - a[j - 1]) * (a[j] - a[j - 1]);
				}
				if(ans > t) {
					t = ans;
					k = 1;
					ll = l;
					rr = r;
				}
				
				//»Ö¸´
				a[l] = tt;
				
				ans = 0;
				tt = a[r];
				a[r] = a[r + 1];
				
				for(int j = 1;j < sz;j++) {
					if(j == tag) continue;
					if(j == tag + 1)  ans += (a[j] - a[j - 2]) * (a[j] - a[j - 2]);
					else ans += (a[j] - a[j - 1]) * (a[j] - a[j - 1]);
				}
				
				if(ans > t) {
					t = ans;
					k = 2;
					ll = l;
					rr = r;
				}
				a[r] = tt;
			}
			
			int tt = a[1];
			a[1] = a[2];
			int ans = 0;
			for(int j = 1;j < sz;j++) {
				if(j == 1) continue;
				if(j == 2) ans += (a[2] - a[0]) * (a[2] - a[0]);
				else ans += (a[j] - a[j - 1]) * (a[j] - a[j - 1]); 
			}
			
			if(ans > t) {
				t = ans;
				k = 2;
				ll = 0, rr = 2;
			}
			a[1] = tt;
			
			ans = 0;
			tt = a[sz - 3];
			a[sz - 3] = a[sz - 4];
			int tag = sz - 2;
			for(int j = 1;j < sz;j++) {
				if(j == tag) continue;
				if(j == tag + 1) ans += (a[j] - a[j - 2]) * (a[j] - a[j - 2]);
				else ans += (a[j] - a[j - 1]) * (a[j] - a[j - 1]); 
			}
			
			if(ans > t) {
				t = ans;
				k = 1;
				ll = sz - 3, rr = sz - 1;
			}
			a[sz - 3] = tt;
			

//			cout << ll << "!" << rr << t << endl;
			cout << t << endl;
			if(k == 1) a[ll] = a[ll - 1];
			else a[rr] = a[rr + 1];
			
			int j = rr;
			while(j < sz) {
				a[j - 1] = a[j];
				j++;
			}
			sz--;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
//		cin >> tt;
	while(tt--) solve();
	
	return 0;
}
