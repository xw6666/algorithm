#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long y , q , seed;
	int res = -1;
	cin >> y >> q >> seed;
	
	int p = 100 - q;
	int cnt = 0;
	
	while(res != 2)
	{
		if(cnt == p)
		{
			printf("%lld\n",y);
		}
		else
		{
			y += 1;
			printf("1\n");
		}
		
		fflush(stdout);
		scanf("%d",&res);
		if(res == 0) cnt ++;
		else cnt = 0;
	}
	
	return 0;
}
