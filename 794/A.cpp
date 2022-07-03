#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int N = 55;
int a[N];

void solve()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	for(int i = 0;i < n;i++) scanf("%d", a + i), sum += a[i];
	

	for(int i = 0;i < n;i++)
	{
		if(((double)sum - a[i]) / (n - 1) == a[i])
		{
			printf("YES\n");
			return;
		}
	}
	
	printf("NO\n");
}

int main()
{
	int tt;
	cin >> tt;
	while(tt--) solve();
	return 0;
}
