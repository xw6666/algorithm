#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;

char s[N];
bool st[N];
int n;
void solve()
{
    
    cin>>n;
    scanf("%s",s+1);
    int res=0;
    for(int i=0;i<n+2;i++) st[i]=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0') {
        for(int j=1;j*i<=n;j++)
        {
            if(st[i*j]) continue;
            if(s[i*j]=='1') break;
            res+=i;
            st[i*j]=true;
        }
        }
    }
    // cout<<endl;
    cout<<res<<endl;
}
signed main()
{
//    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}