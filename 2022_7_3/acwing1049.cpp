//×´Ì¬»úÄ£°å
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 1e9;
int f[N][2], n;
int w[N];

void solve() {
	cin >> n;
	memset(f,0,sizeof(f));
	
	for(int i = 1;i <= n;i++) cin >> w[i];
	f[0][1] = -INF;
	for(int i = 1;i <= n;i++) {
		f[i][0] = max(f[i - 1][0], f[i - 1][1]);
		f[i][1] = f[i - 1][0] + w[i];
	}
	
	cout << max(f[n][0], f[n][1]) << endl;
	
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
