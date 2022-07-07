//1. 组合型顺序枚举
//2. 如果相同长度的木棍搜不到答案，同样相同的木棍不用
//3. 如果第一根没有搜到答案，则错误（反证法）
//4. 如果最后一根没有搜到答案，则错误（反证法）
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>
#define x first 
#define y second

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 65;
int a[N];
bool st[N];
int len;
int sum;
int n;

bool dfs(int u, int v, int w) {
	if(u * len == sum) return true;
	if(v == len) return dfs(u + 1, 0, 0);
	
	for(int i = w;i < n;i++) {
		if(!st[i] && v + a[i] <= len) {
			st[i] = true;
			if(dfs(u, v + a[i], i + 1)) return true;
			st[i] = false;
			
			if(!v) return false;
			if(v + a[i] == len) return false;
			
			int j = i;
			while(j < n  && a[j] == a[i]) j++;
			i = j - 1;
		}
	}
	
	return false;
}

int main() {

	while(cin >> n, n) {
		memset(st,0,sizeof(st));
		sum = 0;
		for(int i = 0;i < n;i++) {
			cin >> a[i];
			sum += a[i];
		}
		
		sort(a, a + n);
		reverse(a, a + n);
		
		len = 1;
		while(1) {
			if(sum % len == 0) {
				bool ans = dfs(0,0,0);
				if(ans) break;
			}
			len++;
		}
		
		cout << len << endl;
	}
	
	return 0;
}


