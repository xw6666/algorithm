#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1011;
int n, m;
int f[N][N];
int a[N];
int b[N];


int main() {
	vector<int> ans;
	n = 1;
	m = 1;
	int x;
	while(scanf("%d", &x), x != -1) b[n++] = x;
	n--;
	while(scanf("%d", &x), x != -1) a[m++] = x;
	m--;
	
	memset(f, 0x3f, sizeof(f));
	for(int i = 0;i <= n;i++) f[i][0] = i;
	for(int i = 1;i <= m;i++) f[0][i] = i;
	
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(a[i] == b[j]) f[i][j] = f[i - 1][j - 1];
			else {
				f[i][j] = min({f[i][j - 1], f[i - 1][j - 1], f[i - 1][j]}) + 1;
			}
		}
	}
	
	cout << f[n][m] << endl;
	
	int i = n, j = m;
	while(i) {
		if(f[i - 1][j - 1] == f[i][j]) {
			i--;
			j--;
			ans.push_back(2);
		} else if(f[i][j - 1] + 1 == f[i][j]) {
			j--;
			ans.push_back(0);
		} else if(f[i - 1][j - 1] + 1 == f[i][j]) {
			i--;
			j--;
			ans.push_back(1);
		} else {
			i--;
			ans.push_back(3);
		}
	}
	
	reverse(ans.begin(), ans.end());
	for(int i = 0;i < ans.size();i++) cout << ans[i];

	
	return 0;
}
