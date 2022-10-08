#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 12, M = 500, P = 1 << 10;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int h[N * N], e[M], ne[M], w[M], idx;
int g[N][N];
int dist[N * N][P];
int n, m, p;
int key[N * N];
bool st[N * N][P];
set<PII> s;
int cnt;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void build() {
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++) {
            int x = g[i][j];
            for(int k = 0;k < 4;k++) {
                int tx = dx[k] + i;
                int ty = dy[k] + j;
                if(!(tx >= 1 && tx <= n && ty >= 1 && ty <= m)) continue;
                int y = g[tx][ty];
                if(!s.count({x, y})) add(x, y, 0);
            }
        }
    }
}




int bfs() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1][0] = 0;
    deque<PII> q;
    q.push_back({1, 0});

    while(q.size()) {
        auto t = q.front();
        q.pop_front();

        if(st[t.x][t.y]) continue;
        st[t.x][t.y] = true;

        if(t.x == n * m) return dist[t.x][t.y];

        if(key[t.x]) {
            int state = t.y | key[t.x];
            if(dist[t.x][state] > dist[t.x][t.y]) {
                dist[t.x][state] = dist[t.x][t.y];
                q.push_front({t.x, state});
            }
        }

        for(int i = h[t.x];~i;i = ne[i]) {
            int j = e[i];
            if(w[i] && !((t.y >> (w[i] - 1)) & 1)) continue;

            if(dist[j][t.y] > dist[t.x][t.y] + 1) {
                dist[j][t.y] = dist[t.x][t.y] + 1;
                q.push_back({j, t.y});
            }
        }
    }

    return -1;
}


int main() {
    cin >> n >> m >> p;
    memset(h, -1, sizeof(h));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) g[i][j] = ++cnt;
    }

    int k;
    cin >> k;
    while(k--) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        int x = g[a][b], y = g[c][d];
        s.insert({x, y});
        s.insert({y, x});

        if(e) {
            add(x, y, e);
            add(y, x, e);
        }
    }


    build();

    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        key[g[a][b]] |= 1 << (c - 1);
    }

    cout << bfs() << endl;
    


    return 0;
}
