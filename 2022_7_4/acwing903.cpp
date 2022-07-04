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
const int N = 110, INF = 0x3f3f3f3f;
int g[N][N];
bool st[N];
int dist[N];
int level[N];
int n,m;

int dijkstra(int down, int up) {
	memset(dist, 0x3f,sizeof(dist));
	memset(st, 0, sizeof(st));
	dist[0] = 0;
	
	for(int i = 0;i < n + 1;i++) {
		int t = -1;
		for(int j = 0;j <= n;j++) {
			if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
		}
		
		st[t] = true;
		
		for(int j = 0;j <= n;j++) {
			if(level[j] >= down && level[j] <= up) {
				dist[j] = min(dist[j], dist[t] + g[t][j]);
			}
		}
	}
	
	return dist[1];
} 

int main() {
	memset(g,0x3f,sizeof(g));
	cin >> m >> n;
	for(int i = 1;i <= n;i++) {
		int w,cnt;
		cin >> w >> level[i] >> cnt;
		g[0][i] = min(g[0][i], w);
		for(int j = 0;j < cnt;j++) {
			int a = i, b, w;
			cin >> b >> w;
			g[b][a] = min(g[b][a], w);
		}
	}
	
	int ans = INF;
	for(int i = level[1] - m;i <= level[1];i++) ans = min(ans, dijkstra(i, i + m));
	
	cout << ans << endl;
	
	return 0;
}
