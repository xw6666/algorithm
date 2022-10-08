#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first 
#define y second  
const int N = 1e5 + 10;
int a[N];
void solve()
{
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++) cin>>a[i];
//	int l=0,r=0;
//	for(int i=0;i<n;i++)
//	{
//		if(a[i]<a[i+1]) l++;
//		else break;
//	}
//	for(int i=n-1;i>=0;i--)
//	{
//		if(a[i-1]>a[i]) r++;
//		else break;
//	}
//	
//	if(l&&r) l++,r++;
////	cout<<l<<" "<<r<<endl;
//	if(a[0]>a[n-1])
//	{
//		
//	}

	int n;
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	
	int l = 0;
	while(l < n - 1 && a[l] < a[l + 1]) l++;
	
	int r = n - 1;
	while(r > 0 && a[r] < a[r - 1]) r--;
	
	int len1 = l + 1, len2 = n - r;
//	cout << len1 << " " << len2 << endl;
	
	if(a[0] > a[n - 1]) {
		if((len1) % 2) {
			cout << "Alice" << endl;
		} else {
			if((len2) % 2 == 0) cout << "Bob" << endl;
			else cout << "Alice" << endl;
		}
	} else {
		if((len2) % 2) cout << "Alice" << endl;
		else {
			if((len1) % 2 == 0) cout << "Bob" << endl;
			else cout << "Alice" << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt = 1;
//		cin >> tt;
	while(tt--) solve();
	
	return 0;
}
