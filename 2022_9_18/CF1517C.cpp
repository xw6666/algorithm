#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 510;
int n;
int g[N][N];

void solve() {
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        g[i][i] = x;
    }

    for(int i = 1;i <= n;i++) {
        int k = g[i][i];
        int x = i, y = i;
        for(int j = 0;j < k - 1;j++) {
            if(x > 1 && y > 1 && !g[x][y - 1]) y--;
            else x++;
            g[x][y] = k;
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i;j++) cout << g[i][j] << " ";
            cout << endl;
    }
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


