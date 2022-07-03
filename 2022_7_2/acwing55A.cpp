#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

int a[100];
int b[100];

int main() {
	int n,m;
	cin >> n >> m;
	for(int i = 0;i < n;i++) scanf("%d", a + i);
	for(int i = 0;i < m;i++) scanf("%d", b + i);
	
	for(int i = 0;i < n;i++) {
		int x = a[i];
		for(int j = 0;j < m;j++) {
			if(b[j] == x) {
				cout << x << " ";
				break;
			}
		}
	}
	return 0;
}
