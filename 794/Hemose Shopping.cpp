#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define LL long long
typedef pair<int,int> PII;

#define io\
ios_base::sync_with_stdio(false); \
cin.tie(NULL);                    \
cout.tie(NULL)

const int N = 1e5 + 10;
int a[N];
int b[N];
int n,x;

void solve()
{
	cin >> n >> x;
	for(int i = 1;i <= n;i++) 
	{
		cin >> a[i];
		b[i] = a[i];
	}
	
	sort(b + 1, b + 1 + n);
	
	if(is_sorted(a + 1, a + 1 + n))
	{
		cout << "YES" << endl;
		return;
	}
	

	if(n >= 2 * x) 
	{
		cout << "YES" << endl;
		return;
	}
	
	for(int i = n - x + 1;i <= x;i++)
	{
		if(a[i] != b[i]) 
		{
			cout << "NO" << endl;
			return;
		}
	}
	
	
	
	cout << "YES" << endl;
}

int main()
{
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
