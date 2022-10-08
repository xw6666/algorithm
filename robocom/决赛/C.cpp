#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 2 * N;
int n, m, k, p;
int h[N], e[N], ne[N], idx;
int w[N];
bool st[N];
int s, t;

void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}


int main() {
	memset(h, -1, sizeof(h));
	cin >> n >> m >> k >> p;
	int sum = 0;
	for(int i = 1;i <= n;i++) scanf("%d", w + i), sum += w[i];
	
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	
	cin >> s >> t;
	cout << w[1] + w[2] << endl;
	
	return 0;
}
