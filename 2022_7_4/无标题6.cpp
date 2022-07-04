#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int a[8];

void solve() {
	
	int h[100] = {0};
	for(int i = 1;i <= 7;i++) {
		if(i <= 5) {
			int t = rand() % 35 + 1;
			while(h[t]) t = rand() % 35 + 1;
			a[i] = t;
		}
		else {
			int t = rand() % 12 + 1;
			while(h[t]) t = rand() % 12 + 1;
			a[i] = t;
		}
	}
	
	for(int i = 1;i <= 7;i++) cout << a[i] << " ";
	cout << endl;
}

int main() {
	int tt;
	cin >> tt;
	srand((unsigned)time(NULL));
	while(tt--) solve();
	
	return 0;
}
