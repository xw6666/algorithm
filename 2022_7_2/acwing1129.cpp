//spfaÄ£°å
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

int n,m,S,T;
const int N = 6210 * 2 + 10;
int h[N],e[N],ne[N],w[N],idx;
bool st[N];
int dist[N];

void add(int a, int b, int c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

void spfa() {
	memset(dist, 0x3f, sizeof(dist));
	dist[S] = 0;
	queue<int> q;
	q.push(S);
	st[S] = true;
	
	while(q.size()) {
		int t = q.front();
		q.pop();
		st[t] = false;
		
		for(int i = h[t];i != -1;i = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if(!st[j]) {
					st[j] = true;
					q.push(j);
				}
			}
		}
	}
}

int main() {
	cin >> n >> m >> S >> T;
	memset(h, -1, sizeof(h));
	
	for(int i = 0;i < m;i++) {
		int a,b,c;
		cin >> a >> b >> c;
		add(a,b,c);
		add(b,a,c);
	}
	
	spfa();
	
	cout << dist[T] << endl;
	
	return 0;
}
