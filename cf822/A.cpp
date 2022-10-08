#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second

const int N = 310;
int a[N];
int n;
void solve() {
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    LL ans = 1e17;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            for(int k = 0;k < n;k++) {
                if(i == j || i == k || j == k) continue;
                ans = min(ans, (LL)abs(a[j] - a[i]) + abs(a[k] - a[i]));
            }
        }
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