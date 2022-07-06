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
int g[N][N];
int n,m,k;
bool st[N];
int dist[N];

bool check(int bound) {
	memset(st,0,sizeof(st));
	memset(dist,0x3f,sizeof(dist));

	dist[1] = 0;
	deque<int> q;
	q.push_back(1);
	
	while(q.size()) {
		int t = q.front();
		q.pop_front();
		
		if(st[t]) continue;
		st[t] = true;
		
		for(int i = 1;i <= n;i++) {
			int x = (g[t][i] > bound);
			if(dist[i] > dist[t] + x && g[t][i] != 0x3f3f3f3f) {
				dist[i] = dist[t] + x;
				if(!x) q.push_front(i);
				else q.push_back(i);
			}
		}
	}

	return dist[n] <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(g,0x3f,sizeof(g));
	cin >> n >> m >> k;
	for(int i = 0;i < m;i++) {
		int a,b,c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	
	int l = 0, r = 1e6 + 1;
	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	
	if(l == 1e6 + 1) l = -1;
	
	cout << l << endl;

	return 0;
}
