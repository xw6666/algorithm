#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;


struct Node{
	int l,r;
	long long w;
}tr[N*4];
int n,m;
void pushup(int u)
{
	
}
void build(int u,int l,int r)
{
	if(l==r) tr[u]={l,r};
	else{
		tr[u]={l,r};
		int mid=(l+r)>>1;
		build(u<<1,l,mid),build(u<<1|1,1,mid+1,r);
		pushup(u);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	 build(1,n);
}
