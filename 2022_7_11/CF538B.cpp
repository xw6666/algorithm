#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

void solve() {
	string s;
	cin >> s;
	vector<int> a;
	for(int i = 0;i < (int)s.size();i++) {
		a.push_back(s[i] - '0');
	}
	
	vector<int> ans;
	while(1) {
		int t = 0;
		for(int i = 0;i < a.size();i++) {
			if(a[i]) {
				a[i]--;
				t = t * 10 + 1;
			} else t = t * 10;
		}
		
		if(t) ans.push_back(t); 
		else break;
	}
	
	cout << ans.size() << endl;
	for(int i = 0;i < ans.size();i++) cout << ans[i] << " ";
	cout << endl;
}

int main() {
	solve();
	
	return 0;
}
