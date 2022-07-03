#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
int pa[N],c[N];
vector<int> son[N];
int ans = 1;

void dfs(int u, int co) {
	if(co != c[u]) ans++, co = c[u];
	for(int i = 0;i < son[u].size();i++) {
		dfs(son[u][i], co);
	}
}

int main() {
	int n;
	cin >> n;
	for(int i = 2;i <= n;i++) {
		scanf("%d", &pa[i]);
		son[pa[i]].push_back(i);
	}
	
	for(int i = 1;i <= n;i++) scanf("%d", c + i);
	
	dfs(1, c[1]);
	
	cout << ans << endl;
	
	return 0;
}
