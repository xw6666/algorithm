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
const int N = 101, M = 1e4 + 1;
int a[N];
bool b[M][M];
vector<int> g[N];
int n;
int ans = 1e9;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

bool check(int z, int t) {
	for(int i = 0;i < g[z].size();i++) {
		if(!b[g[z][i]][t]) return false;
	}
	
	return true;
}

void dfs(int z, int u) {
	if(z >= ans) return ;
	if(u == n) {
		ans = max(ans, z);
		return ;
	}
	
	//放现有的组
	for(int i = 0;i < z;i++) {
		if(check(i, a[u])) {
			g[i].push_back(a[u]);
			dfs(z, u + 1);
			g[i].pop_back();
		}
	}
	
	//新开一个组
	if(z < n) {
		g[z].push_back(a[u]);
		dfs(z + 1, u + 1);
		g[z].pop_back();
	}
}

int main() {
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	
	for(int i = 0;i < n;i++) {
		for(int j = i+ 1;i < n;j++) {
			if(gcd(a[i], a[j]) == 1) b[a[i]][a[j]] = b[a[j]][a[i]] = true;
		}
	}
	
//	dfs(0,0);
	
	return 0;
}
