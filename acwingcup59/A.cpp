#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 420;
int a[N];
int f1[N][N];
int f2[N][N];

int dp1(int l, int r) {
	if(f1[l][r]) return f1[l][r];
	if(l + 1 == r) {
		f1[l][r] = a[l];
		return a[l];
	}
	int maxv = 0;
	for(int i = l + 1;i < r;i++) {
		int t1 = dp1(l, i);
		int t2 = dp1(i, r);
		f1[l][i] = t1;
		f1[i][r] = t2;
		cout << '!' << endl;
	}
	
	return maxv;
}

int main() {
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i], a[n + i] = a[i];
	
	int maxv = 0;
	for(int i = 0;i < n;i++) maxv = max(maxv, dp1(i, i + n));
	
	cout << maxv << endl;
	
}
