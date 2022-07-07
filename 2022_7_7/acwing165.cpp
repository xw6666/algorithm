//dfs
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
const int N = 22;
int a[N];
int b[N];   //车上的状态
int n,w;
int ans;

void dfs(int k, int u) {
	if(k >= ans) return;
	
	if(u == n) {
		ans = min(ans, k);
		return; 
	}
	
	//放现有车上
	for(int i = 0;i < k;i++) {
		if(b[i] + a[u] <= w) {
			b[i] += a[u];
			dfs(k, u + 1);
			b[i] -= a[u];
		}
	}
	
	//新开一辆车
	b[k] += a[u];
	dfs(k + 1, u + 1);
	b[k] -= a[u];
}

int main() {
	cin >> n >> w;
	ans = n;
	for(int i = 0;i < n;i++) cin >> a[i];
	
	sort(a, a + n);
	reverse(a, a + n);
	
	dfs(0,0);
	
	cout << ans << endl;
	
	return 0;
}
