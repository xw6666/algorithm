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

const int N = 1010;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int g[N][N];
PII pre[N][N];
vector<PII> ans;
int n;
bool st[N][N];

void bfs(int sx, int sy) {
	queue<PII> q;
	q.push({sx,sy});
	st[sx][sy] = true;
	
	while(q.size()) {
		auto t = q.front();
		q.pop();
		
		for(int i = 0;i < 4;i++) {
			int x = t.x + dx[i];
			int y = t.y + dy[i];
			if(!(x >= 0 && x < n && y >= 0 && y < n)) continue;
			if(!st[x][y] && g[x][y] == 0) {
				q.push({x, y});
				st[x][y] = true;
				pre[x][y] = {t.x, t.y};
			}
		}
	}
}

int main() {       
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) cin >> g[i][j];
	}
	
	bfs(0,0);

	int sx = 0, sy = 0;
	int x = n - 1, y = n - 1;
	ans.push_back({n - 1, n - 1});
	while(sx != x || sy != y) {
		int a = x, b = y;
		x = pre[a][b].x;
		y = pre[a][b].y;
		ans.push_back({x, y});
	}
	
	for(int i = ans.size() - 1;i >= 0;i--) cout << ans[i].x << " " << ans[i].y << endl;
	
	
	return 0;
}

