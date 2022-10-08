#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
 
void solve() {
    string s;
    cin >> s;
    vector<PII> ans;
    s += s[s.size() - 2];
    ans.push_back({1, s.size() - 2});
    // string t;
    // for(int i = 1;i < s.size() - 1;i++) t += s[i];

    // reverse(t.begin(), t.end());
    ans.push_back({0, s.size() - 1});

    // cout << t[1] << t << s << endl;
    ans.push_back({0, 2});

    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++) {
        if(ans[i].x == 0) cout << 'L' << " " << ans[i].y << endl;
        else cout << 'R' << " " << ans[i].y << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    // cin >> tt;
    tt = 1;
    while(tt--) solve();

    return 0;
}