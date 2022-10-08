#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second

const int N = 1e5 + 10;
int a[N];
int n;

void solve() {
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    LL ans = 0;
    for(int i = 2;i <= n;i++) {
        LL t = a[i] - a[i - 1];
        ans += t - ((LL)n - i + 1) * ((LL)i - 1) * t;
    }

    cout << ans << endl; 
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