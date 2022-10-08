#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second;

// const int N = 2e5 + 10;
// char str[N];

void change(char s[]) {
    if(*s == 'R') *s = 'G';
    else if(*s == 'G') *s = 'R';
    else *s = 'R';
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;

    for(int i = 1;i < n;i++) {
        if(s[i] == s[i - 1]) {
            if(i == n - 1) {
                // if(s[i] == 'R') s[i] = 'G';
                // else if(s[i] == 'G') s[i] = 'R';
                // else s[i] = 'R';
                change(&s[i]);
                cnt++;
            } else {
                if(s[i + 1] != s[i]) s[i] = 'R' + 'G' + 'B' - s[i] - s[i + 1];
                else {
                    change(&s[i]);
                }
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}