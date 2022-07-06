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

void solve() {
	int n;
	scanf("%d", &n);
	if(n % 2) {
		printf("-1\n");
		return;
	}
	
	int ans = n / 2;
	if(ans % 2 == 0) {
		ans++;
	} else ans--;
	printf("%d %d 1\n", ans, ans);
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
