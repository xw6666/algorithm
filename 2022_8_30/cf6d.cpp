#include <bits/stdc++.h>
using namespace std;

const int N = 11;
int n, a, b;
int s[N];
bool st[N];
int ans = 1e9;
int cnt = 0;


void dfs(int u) {
    if(u == n) {
        ans = min(ans, cnt);
        return;
    }

    int t = u;
    for(int i = 1;i < n - 1;i++) {

        if(s[i] < 0 && s[i - 1] < 0 && s[i + 1] < 0) return;
        s[i] -= a;
        s[i - 1] -= b;
        s[i + 1] -= b;
        cnt++;

        if(!st[i]) {
            if(s[i] < 0) {
                st[i] = true;
                t++;
            }
        }

        if(!st[i - 1]) {
            if(s[i - 1] < 0) {
                st[i - 1] = true;
                t++;
            }
        }

        if(!st[i + 1]) {
            if(s[i + 1] < 0) {
                st[i + 1] = true;
                t++;
            }
        }


        dfs(t);
        s[i] += a;
        s[i - 1] += b;
        s[i + 1] += b;
        if(s[i] >= 0) st[i] = false;
        if(s[i - 1] >= 0) st[i] = false;
        if(s[i + 1] >= 0) st[i] = false;
        cnt--;
    }
}

int main() {
    cin >> n >> a >> b;
    for(int i = 0;i < n;i++) scanf("%d", s + i);

    dfs(0);

    cout << ans << endl;

    return 0;
}