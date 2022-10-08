#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
int a[N];
int st[N];
int ha[N];

int check(int n) {
	for(int i = 2;i <= n / i;i++) {
		if(n % i == 0) return i;
	}
	
	return n;
}

void solve() {
	memset(st,0,sizeof(st));
	memset(ha,0,sizeof(ha));
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) scanf("%d", a + i);
	
	int cnt = 0;
	for(int i = 0;i < n;i++) {
		int ans = check(a[i]);
		if(ha[ans]) ans = ha[ans];
		else {
			ha[ans] = ++cnt;
			ans = cnt;
		}
		st[i] = ans;
	}
	
	cout << cnt << endl;
	for(int i = 0;i < n;i++) cout << st[i] << " ";
	cout << endl;
}

int main() {
	
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
