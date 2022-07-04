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
const int N = 510, INF = 0x3f3f3f3f;
bool g[N][N];
int dist[N];
int stop[N];
bool st[N];
int n,m;

void dijkstra() {
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;
	for(int i = 0;i < n;i++) {
		int t = -1;
		for(int j = 1;j <= n;j++) {
			if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
		}
		
		st[t] = true;
		
		for(int j = 1;j <= n;j++) {
			if(g[t][j]) dist[j] = min(dist[j], dist[t] + g[t][j]);
		}
	}
}

int main() {
	cin >> m >> n;
	
	string s;
	getline(cin, s);
	for(int i = 0;i < m;i++) {
		getline(cin, s);
		stringstream ssin(s);
		int cnt = 0, p;
		while(ssin >> p) stop[cnt++] = p;
		
		for(int i = 0;i < cnt;i++) {
			for(int j = i + 1;j < cnt;j++) g[stop[i]][stop[j]] = true;
		}
	}
	
	dijkstra();
	
	if(dist[n] == INF) cout << "NO" << endl;
	else cout << max(dist[n] - 1, 0) << endl;
	
	return 0;
}
