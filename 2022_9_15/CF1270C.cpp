#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second

const int N = 1e5 + 10;
// int a[N];
int n;

void solve() {
    cin >> n;
    LL ans = 0;
    LL cnt = 0;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        ans ^= x;
        cnt += x;
    }

    cout << 2 << endl;
    cout << ans << " " << ans + cnt << endl;
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