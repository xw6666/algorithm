#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <string>
#include <map>
using namespace std;
map<int,int> m;
string a;

int main() {
	cin >> a;
	int minv = 0;
	int maxv = 0;
	bool f = true;
	for(int i = 0;i < a.size();i++) {
		if(!i) f = true;
		else if(a[i] == '+') f = true;
		else if(a[i] == '-') f = false;
		
		if(f) {
			int j = i;
			if(i) j++;
			string x;
			while(j < a.size() && a[j] != '+' && a[j] != '-') {
				x += a[j];
				j++;
			}
			i = j - 1;
			j = 0;
			bool flag = false;
			int u = 0, v = 0;
			for(j = 0;j < x.size();j++) {
				if(x[j] == 'd') {
					flag = true;
					continue;
				}
				
				if(!flag) {
					u = u * 10 + (x[j] - '0');
				} else v = v * 10 + (x[j] - '0');
				
			}
			
			if(flag) {
				
				if(!u) u++;
				m[v] += u;
				minv += u;
				maxv += u * v;
			} else {

				minv += u;
				maxv += u;
			}
			
		} else {
			int j = i;
			if(i) j++;
			string x;
			while(j < a.size() && a[j] != '+' && a[j] != '-') {
				x += a[j];
				j++;
			}
			
			i = j - 1;
			j = 0;
			bool flag = false;
			int u = 0, v = 0;
			for(j = 0;j < x.size();j++) {
				if(x[j] == 'd') {
					flag = true;
					continue;
				}
		
				if(!flag) {
					u = u * 10 + (x[j] - '0');
				} else v = v * 10 + (x[j] - '0');
		
			}
		
			if(flag) {
			
				if(!u) u++;
				m[v] += u;
				minv -= u * v;
				maxv -= u;
			} else {
				
				minv -= u;
				maxv -= u;
			}
		}
	}
	
	
	for(auto& e : m) printf("%d %d\n", e.first, e.second);
	cout << minv << " " << maxv;
	
	return 0;	
}
