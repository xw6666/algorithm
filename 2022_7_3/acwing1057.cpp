//×´Ì¬»údp
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

const int N = 1e5 + 10;
int f[N][110][2], w[N];
int n,k;

int main() {
	cin >> n >> k;
	memset(f, 0xcf, sizeof(f));
	
	for(int i = 1;i <= n;i++) cin >> w[i];

	for(int i = 0;i <= n;i++) f[i][0][0] = 0;
	
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= k;j++) {
			f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
			f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);
		}
	}
	
	int ans = 0;
	for(int i = 0;i <= k;i++) ans = max(ans, f[n][i][0]);
	
	cout << ans << endl;
	
	return 0;
}
