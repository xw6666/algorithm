#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 6010, M = 2 * N;
int h[N], e[M], ne[M], idx;
int a[N];
int f[N][2];
int d[N];
int n;

void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

void dfs(int u, int ls) {
	for(int i = h[u];~i;i = ne[i]) {
		int j = e[i];
		if(j == ls) continue;
		
		dfs(j, u);
		f[u][1] = max(f[u][1], f[j][0] + a[u]);
		f[u][0] = max({f[u][0], f[j][1], f[j][0]});
	}
}

int main() {
	memset(h, -1, sizeof(h));
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	for(int i = 1;i < n;i++) {
		int a, b;
		cin >> a >> b;
		add(b, a);
		d[a]++;
	}
	
	int root = 1;
	while(d[root]) root++;
	
	dfs(root, -1);
	
	cout << max(f[root][0], f[root][1]) << endl;
	
	return 0;
}
