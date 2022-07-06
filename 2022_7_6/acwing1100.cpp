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

const int N = 1e5 + 10;
int dist[N];
bool st[N];
int s, ed;

void bfs() {
	memset(dist,0x3f,sizeof(dist));
	memset(st,0,sizeof(st));
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	st[s] = true;
	
	while(q.size()) {
		auto t = q.front();
		q.pop();
		
		int m[3];
		m[0] = t - 1;
		m[1] = t + 1;
		m[2] = t * 2;
		
		for(int i = 0;i < 3;i++) {
			int x = m[i];
			if(x < 0 || x > 1e5) continue;
			if(!st[x]) {
				st[x] = true;
				q.push(x);
				dist[x] = dist[t] + 1;
				if(x == ed) return;
			}
		}
	}
}

int main() {       
	
	int tt;
	cin >> tt;
	for(int i = 0;i < tt;i++) {
		cin >> s >> ed;
		
		bfs();
		
		cout << dist[ed] << endl;
	}
	
	return 0;
}

