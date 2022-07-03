#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

int main() {
	int n;
	cin >> n;
	int suma = 0;
	int sumb = 0;
	for(int i = 0;i < n;i++) {
		int x;
		cin >> x;
		suma += x;
	}
	
	for(int i = 0;i < n;++i) {
		int x;
		cin >> x;
		sumb += x;
	}
	
	if(suma >= sumb) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
