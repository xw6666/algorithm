#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int co = 0;
vector<int> a[N];
vector<int> b[N];
int cnt[N];
bool mt[N], gb[N],zh[N];
int l[N], r[N];
int c1, c2;

void dfs(int u, bool f1, bool f2, bool f3, bool f4, bool f5, bool f6) {
	if(u == 7) {
		if(f1 && f2 && f3 && f4 && f5 && f6) {
			for(int i = 0;i < c1;i++) a[co].push_back(l[i]), cout << a[co][i] << " ";
			cout << endl;
			for(int i = 0;i < c2;i++) b[co].push_back(r[i]), cout << b[co][i] << " ";
			cout << endl;
			co++;
		}
		return;
	}
	
	if(!cnt[u]) {
		dfs(u + 1, f1, f2, f3, f4, f5, f6);
		return;
	}
	
	
	if(mt[u] && gb[u] && zh[u]) {
		l[c1++] = u;
		dfs(u + 1, true, true, true, f4,f5,f6);
		c1--;
		
		r[c2++] = u;
		dfs(u + 1, f1,f2,f3,1,1,1);
		c2--;
	} else if(mt[u] && gb[u]) {
		l[c1++] = u;
		dfs(u + 1, 1, 1, f3, f4,f5,f6);
		c1--;
		
		r[c2++] = u;
		dfs(u + 1, f1,f2,f3,1,1,f6);
		c2--;
	} else if(gb[u] && zh[u]) {
		l[c1++] = u;
		dfs(u + 1, f1, 1, 1, f4,f5,f6);
		c1--;
		
		r[c2++] = u;
		dfs(u + 1, f1,f2,f3,f4,1,1);
		c2--;
	} else if(mt[u] && zh[u]) {
		l[c1++] = u;
		dfs(u + 1, 1, f2, 1, f4,f5,f6);
		c1--;
		
		r[c2++] = u;
		dfs(u + 1, f1,f2,f3,1,f5,1);
		c2--;
	} else if(mt[u]) {
		l[c1++] = u;
		dfs(u + 1, 1, f2, f3, f4,f5,f6);
		c1--;
		
		r[c2++] = u;
		dfs(u + 1, f1,f2,f3,1,f5,f6);
		c2--;
	} else if(gb[u]) {
		l[c1++] = u;
		dfs(u + 1, f1, 1, f3, f4,f5,f6);
		c1--;
		
		r[c2++] = u;
		dfs(u + 1, f1,f2,f3,f4,1,f6);
		c2--;
	} else if(zh[u]) {
		l[c1++] = u;
		dfs(u + 1, f1, f2, 1, f4,f5,f6);
		c1--;
		
		r[c2++] = u;
		dfs(u + 1, f1,f2,f3,f4,f5,1);
		c2--;
	} else {
		l[c1++] = u;
		dfs(u + 1, f1, f2, f3, f4,f5,f6);
		c1--;
		
		r[c2++] = u;
		dfs(u + 1, f1,f2,f3,f4,f5,f6);
		c2--;
	}
}

int main() {
	for(int i = 1;i <= 6;i++) {
		cin >> cnt[i];
	}
	
	int m = 0;
	for(int i = 1;i <= 6;i++) {
		char op[4];
		scanf("%s", op);
		if(op[0] == '1') mt[i] = true, m++;
		if(op[1] == '1') gb[i] = true;
		if(op[2] == '1') zh[i] = true;
	}
	
	if(m < 2) {
		printf("GG\n");
		return 0;
	}
	
	dfs(1, false, false, false, false, false, false);
	
	
	return 0;	
}
