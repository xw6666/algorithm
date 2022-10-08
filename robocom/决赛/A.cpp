#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int a[N];
int main() {
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) scanf("%d", a + i);
	
	bool flag = false;
	int l = a[0] + 15, r = l + 30 - 1;
	for(int i = 1;i < n;i++) {
		if(a[i] >= l && a[i] <= r && flag == false) {
			flag = true;
			r += 15;
		} else if(a[i] > r) {
			cout << l << " " << r << endl;
			l = a[i] + 15;
			r = l + 29;
			flag = false;
		}
	}
	cout << l << " " << r;
	return 0;
}
