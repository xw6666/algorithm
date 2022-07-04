//n次碓优化dijkstra
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

const int N = 3100, INF = 0x3f3f3f3f;
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];
int tt,n,m;
int a[N];   //存放要求的最短路起点

void add(int a,int b,int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++; 
}


//返回所有奶牛到起点的距离和
int spfa(int S) {
	memset(st,0,sizeof(st));
	memset(dist,0x3f,sizeof(dist));
	queue<int> q;
	st[S] = true;
	dist[S] = 0;
	q.push(S);
	
	while(q.size()) {
		int t = q.front();
		q.pop();
		
		st[t] = false;
		
		for(int i = h[t];i != -1;i = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if(!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	
	int ans = 0;
	for(int i = 0;i < tt;i++) {
		int j = a[i];
		if(dist[j] == INF) return INF;
		ans += dist[j];
	}
	
	return ans;
}

int main() {
	cin >> tt >> n >> m;
	for(int i = 0;i < tt;i++) scanf("%d", a + i);
	
	memset(h,-1,sizeof(h));
	for(int i = 0;i < m;i++) {
		int a,b,w;
		cin >> a >> b >> w;
		add(a,b,w);
		add(b,a,w);
	}
	
	//遍历每个农场做起点做spfa
	int ans = INF;
	for(int i = 1;i <= n;i++) ans = min(ans, spfa(i));
	
	cout << ans << endl;
	
	return 0;
}

