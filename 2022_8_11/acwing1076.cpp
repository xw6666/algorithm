#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 1010;
int g[N][N];
bool st[N][N];
int n;
PII ls[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void bfs(int sx, int sy) {
    st[sx][sy] = true;
    queue<PII> q;
    q.push({sx, sy});

    while(q.size()) {
        auto t = q.front();
        q.pop();

        for(int i = 0;i < 4;i++) {
            int x = dx[i] + t.x;
            int y  = dy[i] + t.y;

            if(x < 0 || x >= n || y < 0 || y >= n || st[x][y] || g[x][y] == 1) continue;
            
            st[x][y] = true;
            ls[x][y] = {t.x, t.y};
            q.push({x, y});
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) cin >> g[i][j];
    }

    bfs(0, 0);

    vector<PII> ans;

    int x = n - 1, y = n - 1;
    ans.push_back({x, y});
    while(x || y) {
        ans.push_back(ls[x][y]);
        int a = x, b = y;
        x = ls[a][b].x;
        y = ls[a][b].y;
    }

    for(int i = ans.size() - 1;i >= 0;i--) cout << ans[i].first << " " << ans[i].second << endl;

    return 0;
}