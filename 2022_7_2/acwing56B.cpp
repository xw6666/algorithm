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

const int N = 2e5 + 10;
int a[N];

int main() {
	int n,k;
	cin >> n >> k;
	for(int i = 0;i < n;i++) scanf("%d", a + i);
	sort(a, a + n);
	stack<int> s;
	s.push(a[0]);
	for(int i = 1;i < n;i++) {
		while(s.size() && a[i] - s.top() <= k && a[i] > s.top()) s.pop();
		s.push(a[i]);
	}
	
	cout << s.size() << endl;
	
	return 0;
}
