#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 1010;
int a[N];
int n,m;

int main() {
	cin >> n >> m;
	int ans = 0;
	int cur = 0;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		if(cur + a[i] > m) {
			cur = 0;
			ans++;
		}
		
		cur += a[i];
	}
	
	cout << ans << endl;
	
	return 0;	
}
