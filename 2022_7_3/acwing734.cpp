//贪心+dp
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e4 + 10;
//(s/l)升序排列之后做01背包
int f[N];
int n;
struct Stone {
	int s,e,l;
	bool operator< (const Stone& W) const {
		return W.s * l > s * W.l;
	}
}stone[110];

void solve() {
	cin >> n;
	int m = 0;
	memset(f,0xcf,sizeof(f));
	for(int i = 0;i < n;i++) {
		int s,e,l;
		cin >> s >> e >> l;
		m += s;
		stone[i] = {s,e,l};
	}
	
	sort(stone, stone + n);
	
	f[0] = 0;
	for(int i = 0;i < n;i++) {
		int s = stone[i].s, e = stone[i].e, l = stone[i].l;
		for(int j = m;j >= s;j--) f[j] = max(f[j], f[j - s] + e - (j - s) * l);	
	}
	
	int ans = 0;
	for(int i = 0;i <= m;i++) ans = max(ans, f[i]);
	cout << ans << endl;
}

int main() {
	int tt;
	cin >> tt;
	for(int i = 1;i <= tt;i++) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
