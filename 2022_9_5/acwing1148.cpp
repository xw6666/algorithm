#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 510, M = 1e4 + 10;

int n, m;
int p[N];
struct Edge {
    int a, b, w;
    bool f;
    bool operator< (const Edge& t) const {
        return w < t.w;
    }
}ed[M];
int dist1[N][N], dist2[N][N];
int h[N], e[2 * N], ne[2 * N], w[2 * N], idx;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void dfs(int u, int ls, int m1, int m2, int d1[], int d2[]) {
    d1[u] = m1, d2[u] = m2;
 
    for(int i = h[u];~i;i = ne[i]) {
        int j = e[i];
        if(j == ls) continue;

        int t1 = m1, t2 = m2;
        if(w[i] > t1) t2 = t1, t1 = w[i];
        else if(w[i] < t1 && w[i] > t2) t2 = w[i];
        
        dfs(j, u, t1, t2, d1, d2);
    }
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for(int i = 0;i < m;i++) {
        cin >> ed[i].a >> ed[i].b >> ed[i].w;
    }
    for(int i = 1;i <= n;i++) p[i] = i;
    sort(ed, ed + m);

    LL sum = 0;
    for(int i = 0;i < m;i++) {
        int a = ed[i].a, b = ed[i].b, w = ed[i].w;
        int pa = find(a), pb = find(b);
        if(pa != pb) {
            add(a, b, w);
            add(b, a, w);
            sum += w;
            p[pa] = pb;
            ed[i].f = true;
        }
    }
    

    for(int i = 1;i <= n;i++) dfs(i, -1, 0, 0, dist1[i], dist2[i]);
    

    LL ans = 1e18;
    for(int i = 0;i < m;i++) {
        if(ed[i].f) continue;
        int a = ed[i].a, b = ed[i].b, w = ed[i].w;
        
        if(w > dist1[a][b]) ans = min(ans, sum + w - dist1[a][b]);
        else if(w > dist2[a][b]) ans = min(ans, sum + w - dist2[a][b]);
    }

    cout << ans << endl;

    return 0;
}