#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second

// const int N = 310;
// int a[N]; 

int n;
void solve() {
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i;j++) {
            if(j == 1 || j == i) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    

    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}