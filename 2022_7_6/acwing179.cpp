//A*
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
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
char op[] = "urdl";

int f(string state) {
	int ans = 0;
	for(int i = 0;i < state.size();i++) {
		if(state[i] != 'x') {
			int t = state[i] - '1';
			ans += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
		}
	}
	
	return ans;
}

string bfs(string st) {
	unordered_map<string, int> dist;
	unordered_map<string, pair<char, string>> pre;
	priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> heap;
	
	heap.push({f(st), st});
	string end = "12345678x";
	while(heap.size()) {
		auto t = heap.top();
		heap.pop();
		
		if(t.y == end) break;
		
		string s = t.y;
		int step = dist[s];
		string backup = s;
		int x,y;
		for(int i = 0;i < s.size();i++) {
			if(s[i] == 'x') {
				x = i / 3;
				y = i % 3;
				break;
			}
		}
		
		for(int i = 0;i < 4;i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if(!(tx >= 0 && tx < 3 && ty >= 0 && ty < 3)) continue;
			
			swap(s[tx * 3 + ty], s[x * 3 + y]);  //ö�ٵ�״̬
			if(dist[s] == 0 || dist[s] > step + 1) {
				dist[s] = step + 1;
				pre[s] = {op[i], backup};
				heap.push({dist[s] + f(s), s});
			}
			
			swap(s[tx * 3 + ty], s[x * 3 + y]);
		}
	}
	
	string ans;
	while(st != end) {
		ans += pre[end].x;
		end = pre[end].y;
	}
	
	reverse(ans.begin(), ans.end());
	
	return ans;
}

int main() {
	string st, c, seq;
	while(cin >> c) {
		st += c;
		if(c != "x") seq += c;
	}
	
	int cnt = 0;
	for(int i = 0;i < seq.size();i++) {
		for(int j = i + 1;j < seq.size();j++) {
			if(seq[j] > seq[i]) cnt++;
		}
	}
	
	if(cnt % 2) cout << "unsolvable" << endl;
	else cout << bfs(st) << endl;
	
	return 0;
}
