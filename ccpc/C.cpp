#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int divide(LL n, bool& f) {
	int ans = 0;
	while(n % 2 == 0) {
		ans++;
		n /= 2;
	}
	if(n==1) f = true;
	return ans;
}
int f(long long a,long long b, bool& ff)
{
	if(a % 2 || b % 2) return 1;
	long long x1=b/2,x2=b*2,y1=a/2,y2 = a * 2;
	return 1 + f(x1, y1, ff^=1);
	
}
void solve()
{
	long long a,b;
	scanf("%lld %lld",&a,&b);
//		bool f1 = false, f2 = false;
//		int res1=divide(a, f1),res2=divide(b, f2);
//		int res=0;
//		res=max(res1,res2);
//		
//		int t;
//		if(res1>res2) t=0;
//		else t=1;
	//	
	//	if(f1&&f2&&res1&&res2)
	//	{
	//		if(t==1) res-=1;
	//	}
	//	 
	//	printf("%d %d\n",res,t);
	//	return ;
	bool ff = 0;
	if(a < b) ff = 1;
	LL ans = f(a, b, ff);
	
	if(a < b) cout << ans << " " << ff << endl;
	else cout << ans << " " << ff << endl;
}
int main()
{
	
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
}
