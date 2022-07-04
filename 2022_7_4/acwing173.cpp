#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define x first 
#define y second
const int N = 1010;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int g[N][N];
bool st[N][N];
int n,m;
queue<PII> q;

void bfs() {
	while(q.size()) {
		auto t = q.front();
		q.pop();
		
		for(int i = 0;i < 4;i++) {
			int x = t.x + dx[i];
			int y = t.y + dy[i];
			
			if(!st[x][y] && x >= 0 && x < n && y >= 0 && y < m) {
				g[x][y] = g[t.x][t.y] + 1;
				st[x][y] = true;
				q.push({x, y});
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			char ch;
			scanf(" %c", &ch);
			g[i][j] = ch - '0';
			if(g[i][j] == 1) {
				q.push({i, j});
				g[i][j] = 0;
				st[i][j] = true;
			}
		}
	}
	
	
	bfs();
	
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) cout << g[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
