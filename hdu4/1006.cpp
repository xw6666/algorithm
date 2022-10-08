#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
double a[N];
int n;

void solve() {
	cin >> n;
	scanf("%d", &n);
	double ans = 0;
	double sum = 0;
		for(int i = 0;i < n;i++) {
			double x;
			scanf("%lf", &x);
			if(ans >= 200) ans += x * 0.5;
			else if(ans >= 100) ans += x * 0.8;
			else ans += x;
				
			sum += x;
		}
		
		if(sum >= 225.0) printf("%.3lf ", 225 + (sum - 225) * 0.5);
		else if(sum >= 100) printf("%.3lf ", 100 + (sum - 100) * 0.8);
		else printf("%.3lf ", sum);
		
		printf("%.3lf\n", ans);
}

int main() {
	int tt;
	cin >> tt;
	while(tt--) solve();
	
	return 0;
}
