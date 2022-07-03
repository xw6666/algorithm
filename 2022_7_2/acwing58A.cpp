#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool flag = false;
	for(int i = 0; i < n;i++) {
		int x;
		cin >> x;
		if(x == 1) flag = true;
	}    
	
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
