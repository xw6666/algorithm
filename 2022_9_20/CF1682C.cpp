#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first 
#define y second

int n;

void solve() {
    cin >> n;
    map<int, int> mp;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    int ans = 0;
    for(auto& e : mp) {
        if(e.y > 2) ans += 2;
        else ans += e.y;
    }

    cout << (ans + 1) / 2 << endl;
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