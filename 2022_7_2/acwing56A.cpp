#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 110;
int h[N];

int main() {
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) {
		int x;
		cin >> x;
		h[x]++;
	}
	
	int ans = 0;
	for(int i = 1;i <= 100;i++) {
		ans = max(ans, h[i]);
	}
	
	cout << ans << '\n';
	
	return 0;
}
