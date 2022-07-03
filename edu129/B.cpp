#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;

const int N = 2e5 + 10;
int a[N];

int main()
{
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0;i < n;i++) scanf("%d", a + i);
		
		int m;
		scanf("%d", &m);
		LL sum = 0;
		for(int i = 0;i < m;i++) 
		{
			LL x;
			scanf("%lld", &x);
			sum += x;
		}
		
		sum %= n;
		printf("%d\n", a[sum]);
	}
	return 0;
}
