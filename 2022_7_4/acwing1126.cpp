#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define x first 
#define y second

const int N = 2010;
double g[N][N];
double dist[N];
bool st[N];
int S, T;
int n,m;

void dijkstra() {
	dist[S] = 1;
	for(int i = 0;i < n;i++) {
		int t = -1;
		for(int j = 1;j <= n;j++) {
			if(!st[j] && (t == -1 || dist[t] < dist[j])) t = j;
		}
		
		st[t] = true;
		
		for(int j = 1;j <= n;j++) {
			dist[j] = max(dist[j], dist[t] * g[t][j]);
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0;i < m;i++) {
		int a,b,c;
		cin >> a >> b >> c;
		double x = (100.0 - c) / 100;
		g[a][b] = g[b][a] = max(g[a][b], x);
	}
	
	cin >> S >> T;
	
	dijkstra();
	
	printf("%.8lf\n", 100 / dist[T]);
	
	return 0;
}
