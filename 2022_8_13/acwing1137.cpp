#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const int N = 1010, M = 30010, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
int n, m, s, ww;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dijkstra() {
    for(int i = 0;i <= n;i++) dist[i] = INF;
    for(int i = 0;i <= n;i++) st[i] = false;


    dist[0] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({dist[0], 0});

    while(heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;
        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver];~i;i = ne[i]) {
            int j = e[i];
            if(dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

void solve() {
    for(int i = 0;i <= n;i++) h[i] = -1;
    idx = 0;

    while(m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b ,&c);
        add(a, b, c);
    }

    cin >> ww;
    while(ww--) {
        int x;
        scanf("%d", &x);
        add(0, x, 0);
    }

    dijkstra();

    if(dist[s] == INF) printf("-1\n");
    else cout << dist[s] << endl;
}

int main() {
    while(cin >> n >> m >> s) solve();

    return 0;
}