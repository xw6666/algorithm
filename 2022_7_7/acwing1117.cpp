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
int n;
string a[N];
int g[N][N];
int ans;
int used[N];
string d;

void dfs(string dragon, int u, int last) {
//	ans = max(ans, (int)dragon.size());
	if(dragon.size() > ans) {
		ans = dragon.size();
		d = dragon;
	}
	
	for(int i = 0;i < n;i++) {
		if(g[last][i] && used[i] < 2) {
			used[i]++;
			dfs(dragon + a[i].substr(g[last][i]), u + 1, i);
			used[i]--;
		}
	}
}

int main() {
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			for(int k = 1;k < min(a[i].size(), a[j].size());k++) {
				if(a[i].substr(a[i].size() - k) == a[j].substr(0, k)) {
					g[i][j] = k;
					break;
				}
			}
		}
	}
	
	
	char ch;
	cin >> ch;
	for(int i = 0;i < n;i++) {
		if(a[i][0] == ch) {
			//可以作为头
			used[i]++;
			dfs(a[i], 1, i);
			used[i]--;
		}
	}
	
	cout << ans << endl;
//	cout << d << endl;
	
	return 0;
}
