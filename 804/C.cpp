#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define x first 
#define y second

const int N = 1e5 + 10, MOD = 1e9 + 7;
int a[N];

void solve() {
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) {
		int x;
		cin >> x;
		a[x] = i;
	}
	
	int l = a[0], r = a[0];
	int cnt = 0, ans = 1;
	
	for(int i = 1;i < n;i++) {
		if(a[i] < l) {
			cnt += l - a[i] - 1;
			l = a[i];
		} else if(a[i] > r) {
			cnt += a[i] - r - 1;
			r = a[i];
		} else {
			ans = ((LL)ans * cnt) % MOD;
			cnt--;
		}
	}
	
	printf("%d\n", ans);
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
