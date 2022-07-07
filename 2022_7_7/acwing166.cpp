//dfs
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
const int N = 9, M = 1e5 + 10;
int row[N], col[N], cell[3][3];
int map[M];
int ones[M];
int str[N][N];
int cnt;

void init() {
	for(int i = 0;i < N;i++) {
		row[i] = col[i] = (1 << N) - 1;
	}
	
	for(int i = 0;i < 3;i++) {
		for(int j = 0;j < 3;j++) {
			cell[i][j] = (1 << N) - 1;
		}
	}
}

void set(int x, int y, int k, bool is_set) {
	int t = 1 << k;
	if(!is_set) t = -t;
	
	row[x] -= t;
	col[y] -= t;
	cell[x / 3][y / 3] -= t;
}

int get(int x, int y) {
	return row[x] & col[y] & cell[x / 3][y / 3];
}

int lowbit(int x) {
	return x & -x;
}


bool dfs(int u) {
	if(u == cnt) {
		for(int i = 0;i < N;i++) {
			for(int j = 0;j < N;j++) cout << str[i][j] << " ";
			cout << endl;
		}
		return true;
	}
	
	//找分支最少的空格
	int x, y;
	int count = 10;
	for(int i = 0;i < N;i++) {
		for(int j = 0;j < N;j++) {
			if(str[i][j] == 0) {
				int t = ones[get(i, j)];
				if(t < count) {
					x = i;
					y = j;
					count = t;
				}
			}
		}
	}
	
	count = get(x, y);
	
	for(int i = count;i;i = i - lowbit(i)) {
		int v = map[lowbit(i)];
		set(x,y,v,true);
		str[x][y] = v + 1;
		int ans = dfs(u + 1);
		if(ans) return true;
		str[x][y] = 0;
		set(x,y,v,false);
	}
	
	return false;
}

int main() {
	
	for(int i = 0;i < N;i++) map[1 << i] = i;
	
	for(int i = 0;i < 1 << N;i++) {
		for(int j = 0;j < N;j++) ones[i] += (i >> j & 1);
	}
	
	init();
	
	for(int i = 0;i < N;i++) {
		for(int j = 0;j < N;j++) {
			cin >> str[i][j];
			if(str[i][j] != 0) {
				set(i,j,str[i][j] - 1, true);
			} else cnt++;
		}
	}
	

	dfs(0);
	
	return 0;
}


