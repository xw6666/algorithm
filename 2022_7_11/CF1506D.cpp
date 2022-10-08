#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
void solve() {
	priority_queue<PII, vector<PII>, less<PII>> heap;
	map<int,int> m;
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) {
		int x;
		scanf("%d", &x);
		m[x]++;
	}
	
	for(auto e : m) {
		heap.push({e.second, e.first});
	}
	
	while(heap.size() >= 2) {
		auto t1 = heap.top();
		heap.pop();
		auto t2 = heap.top();
		heap.pop();
		
		t1.first--;
		t2.first--;
		
		n-= 2;
		if(t1.first) heap.push(t1);
		if(t2.first) heap.push(t2);
	}
	
	cout << n << endl;
}

int main() {
	
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
