#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 60;
int a[N],b[N];

int main()
{
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n,m;
		scanf("%d", &n);
		priority_queue<int, vector<int>, less<int> > q1;
		priority_queue<int, vector<int>, less<int> > q3;
		for(int i = 0;i < n;i++)
		{
			int x;
			scanf("%d", &x);
			q1.push(x);
			q3.push(x);
		}
		
		scanf("%d", &m);
		priority_queue<int, vector<int>, less<int> > q2;
		priority_queue<int, vector<int>, less<int> > q4;
		for(int i = 0;i < m;i++)
		{
			int x;
			scanf("%d", &x);
			q2.push(x);
			q4.push(x);
		}
		
		int cur = q1.top();
		q1.pop();
		bool flag = true;
		while(1)
		{
			while(q2.size() && q2.top() <= cur) q2.pop();
			if(q2.size() == 0) break;
			cur = q2.top();
			q2.pop();
			
			while(q1.size() && q1.top() <= cur) q1.pop();
			if(q1.size() == 0) 
			{
				flag = false;
				break;
			}
			cur = q1.top();
			q1.pop();
		}
		
		if(flag) printf("Alice\n");
		else printf("Bob\n");
		
		flag = true;
		cur = q4.top();
		q4.pop();
		
		while(1)
		{
			while(q3.size() && q3.top() <= cur) q3.pop();
			if(q3.size() == 0) break;
			cur = q3.top();
			q3.pop();
			
			while(q4.size() && q4.top() <= cur) q4.pop();
			if(q4.size() == 0) 
			{
				flag = false;
				break;
			}
			cur = q4.top();
			q4.pop();
		}
		
		if(flag) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}
