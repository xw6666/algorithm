#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;

int a[N];

void solve()
{
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n;i++) scanf("%d", a + i);
	
	int ans = 0;
	int i = 1;
	while(i < n)
	{
		if(a[i] < a[i - 1]) 
		{
			ans++;
			i += 2;
		}
		else i++;
	}
	
	printf("%d\n", ans);
}

int main()
{
	int tt;
	cin >> tt;
	while(tt--) solve();
	return 0;
}
