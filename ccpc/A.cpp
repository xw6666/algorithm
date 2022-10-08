#include <bits/stdc++.h>
using namespace std;

int a[4][14];
int m;
vector<int> alls;

int main() {
	for(int i = 0;i < 4;i++) {
		for(int j = 0;j < 13;j++) {
			int x;
			scanf("%d", &x);
			a[i][x]++;
		}
	}
	
	cin >> m;
	int x, y;   //x≈∆”–y’≈
	for(int i = 0;i < m;i++) {
		char op[2];
		scanf("%s", op);
		if(op[0] == 'S') {
			scanf("%d%d", &x, &y);
			for(int j = 0;j < y;j++) {
				int t;
				scanf("%d", &t);
				alls.push_back(t);
				a[i % 4][t]--;
			}
		} else if(op[0] == '!') {
			scanf("%d", &y);
			for(int j = 0;j < y;j++) {
				int t;
				scanf("%d", &t);
				alls.push_back(t);
				a[i % 4][t]--;
			}
		} else {
			bool flag = true;
			for(int j = alls.size() - 1;j >= alls.size() - 1 - y + 1;j--) {
				if(alls[j] != x) {
					flag = false;
					break;
				}
			}
			
			if(flag) {
				for(int j = 0;j < alls.size();j++) a[i % 4][alls[j]]++;
			} else {
				for(int j = 0;j < alls.size();j++) a[(i % 4 - 1 + 4) % 4][alls[j]]++;
			}
			alls.clear();
		}
	}
	
	for(int i = 0;i < 4;i++) {
		for(int j = 1;j <= 13;j++) {
			for(int k = 0;k < a[i][j];k++) {
				printf("%d ",j);
			}
		}
		printf("\n");
	}

	return 0;
}
