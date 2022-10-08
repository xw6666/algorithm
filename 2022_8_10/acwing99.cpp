#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n, r;
int s[N][N];

int main() {
    cin >> n >> r;
    r = min(r, 5001);
    r--;


    for(int i = 0;i < n;i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        s[x + 1][y + 1] += w;
    }

    for(int i = 1;i <= 5001;i++) {
        for(int j = 1;j <= 5001;j++) s[i][j] += (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]);
    }

    int ans = 0;
    for(int i = 1;i <= 5001;i++) {
        for(int j = 1;j <= 5001;j++) {
            if(i <= r || j <= r) continue;
            ans = max(ans, s[i][j] - s[i - r - 1][j] - s[i][j - r - 1] + s[i - r - 1][j - r - 1]);
        }
    }

    cout << ans << endl;

    return 0;
}