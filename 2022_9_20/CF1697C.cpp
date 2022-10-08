#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first 
#define y second


void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;

    for(int i = 0, j = 0;i < n;i++, j++) {
        while(i < n && a[i] != 'a') i++;
        while(j < n && b[j] != 'a') j++;
        if(i < n && j < n) {
            if(i > j) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    for(int i = 0, j = 0;i < n;i++, j++) {
        while(i < n && a[i] != 'c') i++;
        while(j < n && b[j] != 'c') j++;
        if(i < n && j < n) {
            if(i < j) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    string s1, s2;
    for(int i = 0;i < n;i++) {
        if(a[i] != 'b') s1 += a[i];
        if(b[i] != 'b') s2 += b[i];
    }

    if(s1 == s2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}