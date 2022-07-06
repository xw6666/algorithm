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
const int N = 55;
int g[N][N];
bool st[N][N];
int n,m;

int bfs(int sx, int sy) {
	queue<PII> q;
	st[sx][sy] = true;
	q.push({sx,sy});
	int ans = 1;
	
	while(q.size()) {
		auto t = q.front();
		q.pop();
		
		int x = t.x, y = t.y;
		int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
		
		for(int i = 0;i < 4;i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if(!(tx >= 0 && tx < n && ty >= 0 && ty < m)) continue;
			if(st[tx][ty]) continue;
			if((g[x][y] >> i) & 1) continue;
			
			st[tx][ty] = true;
			ans++;
			q.push({tx,ty});
		}
	}
	
	return ans;
}

int main() {       
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) cin >> g[i][j];
	}
	
	int ans = 0;
	int cnt = 0;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if(!st[i][j]) {
				ans = max(ans, bfs(i, j));
				cnt++;
			}
		}
	}
	
	cout << cnt << endl;
	cout << ans << endl;

	return 0;
}

