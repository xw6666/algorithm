//dijkstra+dfs–Ú
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
const int N = 50010, M =21e5 + 10, INF = 0x3f3f3f3f;
int h[N],e[M],ne[M],w[M],idx;
int S[7];
int n,m;
bool st[N];
int dist[7][N];
vector<int> alls;
int ans = INF;

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}


void dijkstra(int u) {
	memset(st,0,sizeof(st));
	dist[u][S[u]] = 0;
	
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	heap.push({0,S[u]});
	
	while(heap.size()) {
		auto t = heap.top();
		heap.pop();
		int ver = t.second;
		
		if(st[ver]) continue;
		st[ver] = true;
		
		for(int i = h[ver];i != -1;i = ne[i]) {
			int j = e[i];
			if(dist[u][j] > dist[u][ver] + w[i]) {
				dist[u][j] = dist[u][ver] + w[i];
				heap.push({dist[u][j], j});
			}
		}
	}
}

void dfs(int u) {
	if(u >= 5) {
		int res = dist[0][S[alls[0]]];
		for(int i = 0;i < alls.size() - 1;i++) {
			res += dist[alls[i]][S[alls[i + 1]]];
		}
		
		ans = min(ans, res);
		return;
	}
	
	for(int i = 1;i <= 5;i++) {
		if(!st[i]) {
			st[i] = true;
			alls.push_back(i);
			dfs(u + 1);
			st[i] = false;
			alls.pop_back();
		}
	}
}

int main() {
	memset(h, -1, sizeof(h));
	cin >> n >> m;
	for(int i = 1;i <= 5;i++) cin >> S[i];
	
	for(int i = 0;i < m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c);
		add(b,a,c);
	}
	
	memset(dist, 0x3f, sizeof(dist));
	S[0] = 1;
	for(int i = 0;i < 6;i++) dijkstra(i);
	
	memset(st, 0, sizeof(st));
	dfs(0);
	
	cout << ans << endl;

	return 0;
}
