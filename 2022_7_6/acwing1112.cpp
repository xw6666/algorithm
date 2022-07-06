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

const int N = 110;
char g[N][N];
bool st[N][N];
int n;
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

void dfs(int sx, int sy, int edx, int edy) {
	st[sx][sy] = true;
	if(st[edx][edy]) return;
	
	for(int i = 0;i < 4;i++) {
		if(st[edx][edy]) return;
		int x = sx + dx[i];
		int y = sy + dy[i];
		
		if(!st[x][y] && g[x][y] == '.') dfs(x, y, edx, edy);
	}
}

void solve() {
	memset(st,0,sizeof(st));
	cin >> n;
	for(int i = 0;i < n;i++) scanf("%s", g[i]);
	
	int sx,sy,edx,edy;
	cin >> sx >> sy >> edx >> edy;
	if(g[sx][sy] == '#' || g[edx][edy] == '#') {
		cout << "NO" << endl;
		return;
	}
	
	dfs(sx,sy,edx,edy);
	
	if(st[edx][edy]) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
		
	return 0;
}
