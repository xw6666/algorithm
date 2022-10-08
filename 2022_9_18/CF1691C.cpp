#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 1e5 + 10;
int n, k;

void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    if(s.size() == 1) {
        if(s[0] == '1') cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }

    LL ans = 0;
    bool f1 = false;
    bool f2 = false;

    int mind = 1e9;
    int maxd = -1;
    if(s[0] == '1') ans += 10, f1 = true, mind = min(mind, 0), maxd = max(maxd, 0);
    if(s[s.size() - 1] == '1') ans++, f2 = true, mind = min(mind, n - 1), maxd = max(maxd, n - 1);


    for(int i = 1;i < s.size() - 1;i++) {
        if(s[i] == '1') {
            ans += 11;
            mind = min(mind, i);
            maxd = max(maxd, i);
        }
    }


    bool f = false;
    if(maxd != -1 && !f2 && n - 1 - maxd <= k && maxd != n - 1) {
        k -= (n - 1 - maxd);
        ans -= 10;
        if(maxd == 0) ans++;
        f = true;
    }
    if(mind != 1e9 && !f1 && mind <= k && mind != 0 && mind != n - 1) {
        if(!(f == true && maxd == mind)) ans--; 

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


