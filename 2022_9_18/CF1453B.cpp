#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second

const int N = 2e5 + 10;
int a[N], b[N];
int n;


void solve() {
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i], b[i] = a[i] - a[i - 1];

    int x = abs(b[n]);
    x = max(x, abs(b[2]));     //注意这里可以直接贡献

    for(int i = 2;i < n;i++) {
        if((b[i] > 0 && b[i + 1] < 0) || (b[i] < 0 && b[i + 1] > 0)) {
           int t = min(abs(b[i]), abs(b[i + 1]));
           if(2 * t > x) {
                x = t * 2;
           } 
        }
    }


    LL ans = 0;
    for(int i = 2;i <= n;i++) ans += abs(b[i]);

    cout << ans - x << endl;
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


