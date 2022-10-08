#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;
const int N = 1010;
int a[N];
int n,m;
int last[N];

int main() {
	cin >> n >> m;
	memset(last,-1,sizeof(last));
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	while(m--) {
		int t, k;
		cin >> t >> k;
		while(k--) {
			int x;
			cin >> x;
			if(last[x] == -1 || a[x] == -1 || abs(t - last[x]) >= a[x]) {
				last[x] = t;
			} else {
				printf("Don't take %d at %d!\n", x, t);
			}
		}
	}
	
	return 0;	
}
