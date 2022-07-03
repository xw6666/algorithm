//Ì°ĞÄ¾­µäÀıÌâ
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define x first 
#define y second
const int N = 50010;
PII a[N];
LL sum[N];

int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		int w,s;
		cin >> w >> s;
		a[i].x = w + s;
		a[i].y = s;
	}
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + (a[i - 1].x - a[i - 1].y);
	
	
	LL ans = -1e9;
	for(int i = 1;i <= n;i++) ans = max(ans, sum[i] - a[i].y);
	
	cout << ans << endl;
	
	return 0;
}
