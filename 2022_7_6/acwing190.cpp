//双向广搜
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
#define x first 
#define y second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N = 6;
int n;  //规则数
string A, B;
string a[N], b[N];

int extend(queue<string>& q, unordered_map<string,int>& da, unordered_map<string,int>& db, string a[N], string b[N]) {
	string t = q.front();
	q.pop();
	
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < t.size();j++) {
			if(t.substr(j, a[i].size()) == a[i]) {
				//可以替换
				string str = t.substr(0, j) + b[i] + t.substr(j + a[i].size());
				if(db.count(str)) return da[t] + db[str] + 1;
				if(da.count(str)) continue;
				da[str] = da[t] + 1;
				q.push(str);
			}
		}
	}
	
	return 11;
}

int bfs() {
	if(A == B) return 0;
	
	queue<string> qa,qb;
	unordered_map<string,int> da,db;
	
	qa.push(A);
	qb.push(B);
	da[A] = 0;
	da[B] = 0;
	
	while(qa.size() && qb.size()) {
		int d;
		if(qa.size() < qb.size()) {
			d = extend(qa,da,db,a,b);
		} else {
			d = extend(qb,db,da,b,a);
		}
		if(d <= 10) return d;
	}
	
	
	return 11;
}

int main() {       
	cin >> A >> B;
	while(cin >> a[n] >> b[n]) n++;
	
	int ans = bfs();
	if(ans > 10) cout << "NO ANSWER!" << endl;
	else cout << ans << endl;
	
	return 0;
}

