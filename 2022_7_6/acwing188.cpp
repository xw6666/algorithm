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

const int N = 155;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
char g[N][N];
bool st[N][N];
int dist[N][N];
int n,m;
int sx,sy;
int endx, endy;

void bfs() {
	memset(dist,0x3f,sizeof(dist));
	queue<PII> q;
	q.push({sx,sy});
	st[sx][sy] = true;
	dist[sx][sy] = 0;
	
	while(q.size()) {
		auto t = q.front();
		q.pop();
		
		for(int i = 0;i < 8;i++) {
			int x = t.x + dx[i];
			int y = t.y + dy[i];
			
			if(!(x >= 0 && x < n && y >= 0 && y < m)) continue;
			if(!st[x][y] && g[x][y] != '*') {
				st[x][y] = true;
				dist[x][y] = dist[t.x][t.y] + 1;
				if(g[x][y] == 'H') return;
				q.push({x,y});
			}
		}
	}
}

int main() {       
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for(int i = 0;i < n;i++) scanf("%s", g[i]);
	
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(g[i][j] == 'K') {
				sx = i;
				sy = j;
			}
			if(g[i][j] == 'H') {
				endx = i;
				endy = j;
			}
		}
	}
	
	bfs();
	
	cout << dist[endx][endy] << endl;
	
	return 0;
}

