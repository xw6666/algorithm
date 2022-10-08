#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
int d[N][N];
int l[N];
int n;
bool st[N];

void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
} 

void bfs() {
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) st[j] = false;
		d[i][i] = 0;
		queue<int> q;
		q.push(i);
		st[i] = true;
		
		while(q.size()) {
			int t = q.front();
			q.pop();
			
			for(int j = h[t];j != -1;j = ne[j]) {
				int k = e[j];
				if(!st[k]) {
					st[k] = true;
					d[i][k] = d[i][t] + 1;
					q.push(k);
				}
			}
		}
	}
}

int main() {
	cin >> n;
	memset(h, -1, sizeof(h));
	for(int i = 1;i < n;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	
	for(int i = 1;i <= n;i++) scanf("%d", l + i);
	
	bfs();
	
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = i + 1;j <= n;j++) {
			for(int k = j + 1;k <= n;k++) {
				if(l[i] != l[j] && l[j] != l[k] && l[k] != l[i]) {
					if(d[i][j] == d[i][k] && d[k][j] == d[k][i]) ans++;
				}
			}
			
//			cout << d[i][j] << " " << d[j][i] << " " << i << " " << j << endl;
		}
	}
	
	
	
	cout << ans << endl;
	
	return 0;
}
