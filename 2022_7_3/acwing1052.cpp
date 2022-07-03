//kmp+状态机+dp
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
#define x first
#define y second 
const int N = 55, mod = 1e9 + 7;
int f[N][N];   //已经编写i个密码的情况下，匹配上了str中1到j的数量有f[i][j]
int n;
int ne[N];
char str[N];

int main() {
	cin >> n >> str + 1;
	auto m = strlen(str + 1);
	//kmp模板
	for(int i = 2,j = 0;i <= m;i++) {
		while(j && str[j + 1] != str[i]) j = ne[j];
		if(str[j + 1] == str[i]) j++;
		ne[i] = j;
	}
	
	f[0][0] = 1;   
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			for(char k = 'a';k <= 'z';k++) {
				//做一下kmp匹配
				int u = j;
				while(u && str[u + 1] != k) u = ne[u];
				if(str[u + 1] == k) u++;
				
				if(u < m) f[i + 1][j] = (f[i + 1][j] + f[i][u]) % mod;
			}
		}
	}
	
	int ans = 0;
	for(int i = 0;i < m;i++) ans = (ans + f[n][i]) % mod;
	
	cout << ans << endl;
	
	return 0;
}
