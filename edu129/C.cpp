#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> PII;
#define x first  
#define y second
const int N = 110;


void solve()
{

	int n;
	cin >> n;
	vector<PII> a(n, {0,0});
	for(int i = 0;i < n;i++) scanf("%d", &a[i].x);	
	for(int i = 0;i < n;i++) scanf("%d", &a[i].y);
	vector<PII> b = a;
	
	sort(b.begin(), b.end());
	
	for(int i = 0;i < b.size() - 1;i++)
	{
		if(b[i].y > b[i + 1].y) 
		{
			printf("-1\n");
			return;
		}
	}
	
	vector<PII> ans;
	for(int i = 0;i < n - 1;i++)
	{
		bool flag = true;
		for(int j = 0;j < n - 1 - i;j++)
		{
			if(a[j].x > a[j + 1].x)
			{
				swap(a[j], a[j + 1]);
				ans.push_back({j, j + 1});
				flag = false;
			}
			else if(a[j].y > a[j + 1].y)
			{
				swap(a[j], a[j + 1]);
				ans.push_back({j, j + 1});
				flag = false;
			}
		}
		if(flag) break;
	}
	
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d %d\n", ans[i].x + 1, ans[i].y + 1);
	
}

int main()
{
	int tt;
	cin >> tt;
	
	while(tt--) solve();
	return 0;
}
