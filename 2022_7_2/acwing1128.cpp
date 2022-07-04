//dijkstraÄ£°å
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

const int N = 500;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];
int n,m;

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
	memset(dist,0x3f,sizeof(dist));
	dist[1] = 0;
	for(int i = 0;i < n;i++) {
		int t = -1;
		for(int j = 1;j <= n;j++) {
			if(!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
		}
		
		st[t] = true;
		
		for(int j = h[t];j != -1;j = ne[j]) {
			int k = e[j];
			dist[k] = min(dist[k], dist[t] + w[j]);
		}
	}
}

int main() {
	cin >> n >> m;
	memset(h,-1,sizeof(h));
	for(int i = 0;i < m;i++) {
		int a,b,w;
		cin >> a >> b >> w;
		add(a,b,w);
		add(b,a,w);
	}
	
	dijkstra();
	
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		if(dist[i] == 0x3f3f3f3f) {
			cout << -1 << endl;
			return 0;
		}
		ans = max(ans, dist[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}
