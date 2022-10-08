#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int lg[3];
int hg[3];
int ld[3];
int hd[3];
int d1, d2;
int dx, dy;
vector<PII> a;

bool check(int x, int y) {
	lg[1] += ld[1];
	lg[2] -= ld[2];
	if(x == hg[1] || x == hg[2] || y == lg[1] || y == lg[2]) {
		lg[1] -= ld[1];
		lg[2] += ld[2];
		return false;
	}
	
	lg[1] -= ld[1];
	lg[2] += ld[2];
	
//	cout << "---" << dx << " " << dy << " " << x << " " << y << endl;
	
	if(abs(dx - x) + abs(dy - y) == d2) return true;
	return false;
}

void get(int x, int y) {
	a.clear();
	hg[1] -= hd[1];
	hg[2] += hd[2];
	if(x == hg[1] || x == hg[2] || y == lg[1] || y == lg[2]) {
		hg[1] += hd[1];
		hg[2] -= hd[2];
		return;
	}

	for(int i = 1;i <= 5;i++) {
		for(int j = 1;j <= 5;j++) {
			if(i == x && j == y) continue;
			
			if(abs(i - x) + abs(j - y) == d1) {
				if(check(i, j)) a.push_back({i, j});
			}
		}
	}
	
	hg[1] += hd[1];
	hg[2] -= hd[2];
}

int main() {
	cin >> lg[1] >> lg[2] >> hg[1] >> hg[2];
	cin >> ld[1] >> ld[2] >> hd[1] >> hd[2];
	cin >> dx >> dy >> d1 >> d2;
	
	for(int i = 1;i <= 5;i++) {
		for(int j = 1;j <= 5;j++) {
			get(i, j);
			
			for(int k = 0;k < a.size();k++) {
				cout << i << " " << j << " " << a[k].first << " " << a[k].second << endl;
			}
		}
	}
	
	return 0;
}
