#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first 
#define y second

int n;

void solve() {
    cin >> n;
    string s;
    cin >> s;
    char ch = 'z' + 1;
    for(int i = 0;i < s.size();i++) ch = min(ch, (char)s[i]);

    vector<int> key;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == ch) key.push_back(i);
    }

    int ans = n + 1;
    string bup = s;
    for(int i = 0;i < key.size();i++) {
        int k = key[i];
        string t = s;
        for(int i = 0;i < t.size() - k;i++) {
            int l = i, r = i + k;
            while(l < r) {
                swap(t[l], t[r]);
                l++, r--;
            }
        }
        if(t < bup) {
            ans = k;
            bup = t;
        } else if(t == bup) ans = min(ans, k);
    }

    cout << bup << endl;
    cout << ans + 1 << endl;
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