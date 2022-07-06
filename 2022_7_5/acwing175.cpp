#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <deque>
#pragma GCC optimize(2)
#define x first 
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 510, M = 2 * N;
char g[N][N];
int dist[M][M];
bool st[M][M];
int n,m;

int bfs() {
	memset(dist, 0x3f, sizeof(dist));
	memset(st, 0, sizeof(st));
	
	deque<PII> q;
	q.push_front({0,0});
	dist[0][0] = 0;
	
	while(q.size()) {
		auto t = q.front();
		q.pop_front();
		
		int x = t.x, y = t.y;
		if(st[x][y]) continue;
		st[x][y] = true;
		
		if(x == n && y == m) return dist[n][m];
		
		int dx[] = {-1,-1,1,1}, dy[] = {-1,1,1,-1};
		int ix[] = {-1,-1,0,0}, iy[] = {-1,0,0,-1};
		char ch[5] = "\\/\\/";
		
		for(int i = 0;i < 4;i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			
			if(tx >= 0 && tx <= n && ty >= 0 && ty <= m) {
				int ga = x + ix[i];
				int gb = y + iy[i];
				int w = (ch[i] != g[ga][gb]);  //相等边权为0
				int d = dist[x][y] + w;
				if(d < dist[tx][ty]) {
					dist[tx][ty] = d;
					if(!w) q.push_front({tx, ty});
					else q.push_back({tx, ty});
				}
				
			}
		}
	}
	
	return dist[n][m];
}

void solve() {
	cin >> n >> m;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) cin >> g[i][j];
	}
	
	int ans = bfs();
	
	if(ans == 0x3f3f3f3f) cout << "NO SOLUTION" << endl;
	else cout << dist[n][m] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
