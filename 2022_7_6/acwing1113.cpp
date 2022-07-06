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

const int N = 40;
char g[N][N];
bool st[N][N];
int n, m;
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};


int dfs(int sx, int sy) {
	st[sx][sy] = true;
	int cnt = 1;
	
	for(int i = 0;i < 4;i++) {
		int x = sx + dx[i];
		int y = sy + dy[i];
		if(!(x >= 0 && x < n && y >= 0 && y < m)) continue;
		
		if(!st[x][y] && g[x][y] != '#') cnt += dfs(x, y);
	}
	
	return cnt;
}

void solve() {
	memset(st,0,sizeof(st));
	for(int i = 0;i < n;i++) scanf("%s", g[i]);
	
	int sx,sy;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if(g[i][j] == '@') {
				sx = i;
				sy = j;
			}
		}
	}
	
	
	cout << dfs(sx,sy) << endl;
}


int main() {
	while(cin >> m >> n, m || n) solve();
	
	return 0;
}
