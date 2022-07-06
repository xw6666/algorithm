#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
int g[2][4];
unordered_map<string, int> dist;
unordered_map<string, pair<char, string>> pre;

void set(string t) {
	for(int i = 0;i < 4;i++) g[0][i] = t[i];
	
	for(int i = 3,j = 4;i >= 0;i--, j++) g[1][i] = t[j];
}

string get() {
	string ans;
	for(int i = 0;i < 4;i++) ans += g[0][i];
	for(int i = 3;i >= 0;i--) ans += g[1][i];
	
	return ans;
}

string move0(string t) {
	set(t);
	for(int i = 0;i < 4;i++) swap(g[0][i], g[1][i]);
	
	return get();
}

string move1(string t) {
	set(t);
	int s = g[0][3], v = g[1][3];
	g[0][3] = g[0][2], g[1][3] = g[1][2];
	g[0][2] = g[0][1], g[1][2] = g[1][1];
	g[0][1] = g[0][0], g[1][1] = g[1][0];
	g[0][0] = s, g[1][0] = v;
	
	return get();
}

string move2(string t) {
	set(t);
	int v = g[0][1];
	g[0][1] = g[1][1];
	g[1][1] = g[1][2];
	g[1][2] = g[0][2];
	g[0][2] = v;
	
	return get();
}

void bfs(string st, string ed) {
	if(st == ed) return;
	
	dist[st] = 0;
	queue<string> q;
	q.push(st);
	
	while(q.size()) {
		string t = q.front();
		q.pop();
		
		string m[3];
		m[0] = move0(t);
		m[1] = move1(t);
		m[2] = move2(t);
		
		for(int i = 0;i < 3;i++) {
			if(dist.count(m[i]) == 0) {
				dist[m[i]] = dist[t] + 1;
				pre[m[i]] = {char(i + 'A'), t};
				if(m[i] == ed) return;
				q.push(m[i]);
			}
		}
	}
}

int main() {
	string ed;
	for(int i = 0;i < 8;i++) {
		int x;
		cin >> x;
		ed += (x + '0');
	}
	
	string st;
	for(int i = 1;i <= 8;i++) st += (i + '0');
	
	bfs(st, ed);
	
	cout <<  dist[ed] << endl;
	
	string ans;
	while(ed != st) {
		ans += pre[ed].first;
		ed = pre[ed].second;
	}
	
	reverse(ans.begin(), ans.end());
	
	if(ans.size()) cout << ans << endl;
	
	
	return 0;
}
