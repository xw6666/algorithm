#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int a[N];

int main() {
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int res=(n-1)/(k-1)+((n-1)%(k-1)||0);
	
	cout << res;
	
	return 0;
}
