#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 510;
typedef long long LL;
int n;

void solve() {
    cin >> n;
    LL ans = 1;
    cin >> ans;

    for(int i = 0;i < n - 1;i++) {
        int x;
        scanf("%d", &x);
        ans = (ans * (x + 1)) % MOD;
    }

    cout << ans - 1 << endl;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}