#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];int w[5];
int main()
{	
	int T;
	cin>>T;	
	while(T--)
	{
		int n,s=0;
		cin>>n;	
		for(int i=0;i<n;i++)
		{			
			cin>>a[i];
			if(a[i]!=0) w[s++]=a[i];
		}		
		if(s==0)cout<<"YES"<<endl;
		else if(s==2)		
		{			
			if(w[0]==-w[1])cout<<"YES"<<endl;
			else cout<<"NO"<<endl;	
		}		
		else if(s==4&&n==4)		
		{			
			sort(w,w+4);			
			if(w[0]==-w[3]&&w[1]==-w[2])
				cout<<"YES"<<endl;			
			else cout<<"NO"<<endl;
		}		
		else if(n==3&&s==3)		
		{			
			if(w[0]==-w[2]||w[0]==-w[1]||w[1]==-w[2]) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;		
		}		
		else if(s==1)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;	
	}	
	return 0;
	
}
