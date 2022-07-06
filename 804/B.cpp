#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define x first 
#define y second

const int N = 55;
int g[N][N];

void solve() {
	int n,m;
	cin >> n >> m;
	memset(g,0,sizeof(g));
	
	bool flag = true;
	for(int i = 1;i <= n;i += 2) {
		for(int j = 1;j <= m;j += 2) {
			if(flag) {
				g[i][j] = g[i + 1][j + 1] = 1;
				flag = false;
			} else {
				g[i + 1][j] = g[i][j + 1] = 1;
				flag = true;
			}
		}
		if((m / 2) % 2 == 0) flag = !flag;
	}
	
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) printf("%d ", g[i][j]);
		printf("\n");
	}
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
