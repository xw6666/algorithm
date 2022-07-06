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
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int g[N][N];
int st[N][N];
int n;

void bfs(int sx, int sy, bool& feng, bool& gu) {
	queue<PII> q;
	q.push({sx, sy});
	st[sx][sy] = true;
	
	while(q.size()) {
		auto t = q.front();
		q.pop();
		
		int x = t.x;
		int y = t.y;

		for(int i = 0;i < 8;i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			
			if(!(tx >= 0 && tx < n && ty >= 0 && ty < n)) continue;
			
			if(g[x][y] < g[tx][ty]) gu = true;
			else if(g[x][y] > g[tx][ty]) feng = true;
			else if(!st[tx][ty]) {
				q.push({tx, ty});
				st[tx][ty] = true;
			}
		}
	}
}

int main() {       
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i = 0;i < n;i++) 
		for(int j = 0;j < n;j++)
			cin >> g[i][j];
	
	
	int a = 0, b = 0;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(!st[i][j]) {
				bool feng = false;
				bool gu = false;
				bfs(i,j,feng,gu);
				if(!feng) b++;
				if(!gu) a++;
			}
		}
	}
	
	cout << a << " " << b << endl;
	
	return 0;
}

