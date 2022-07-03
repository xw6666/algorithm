#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int a[N],q[N];

int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) scanf("%d", a + i);
	
	int i = 0, j = 1;
	int len = 1;
	while(j < n) {
		while(j < n && a[j - 1] * 2 >= a[j]) j++;
		len = max(len, j - i);
		i = j;
		j++;
	}
	
	cout << len << endl;
	
	return 0;
}
