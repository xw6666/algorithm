//×´Ì¬»úÄ£ÐÍ
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
int n;
int f[N][3];
int w[N];

int main() {
	cin >> n;
	for(int i = 1;i <= n;i++) scanf("%d", w + i);
	
	memset(f,0xcf,sizeof(f));
	f[0][2] = 0;
	for(int i = 1;i <= n;i++) {
		f[i][0] = max(f[i - 1][0], f[i - 1][2] - w[i]);
		f[i][1] = f[i - 1][0] + w[i];
		f[i][2] = max(f[i - 1][1], f[i - 1][2]);
	}
	
	cout << max(f[n][1], f[n][2]) << endl;
	
	return 0;
}
