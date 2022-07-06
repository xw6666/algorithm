//dfs
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <deque>
#define x first 
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 10;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool st[N][N];
int n, m;
int ans;

void dfs(int cnt, int sx, int sy) {
	if(cnt == n * m) {
		ans++;
		return;
	}
	
	for(int i = 0;i < 8;i++) {
		int x = sx + dx[i];
		int y = sy + dy[i];
		if(!(x >= 0 && x < n && y >= 0 && y < m)) continue;
		if(!st[x][y]) {
			st[x][y] = true;
			dfs(cnt + 1, x, y);
			st[x][y] = false;
		}
	}
}

void solve() {
	int sx,sy;
	cin >> n >> m >> sx >> sy;
	ans = 0;
	st[sx][sy] = true;
	dfs(1, sx, sy);
	
	cout << ans << endl;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
