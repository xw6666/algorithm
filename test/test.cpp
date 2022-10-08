#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second

const int N = 1e5 + 10, M = 2 * N, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
bool st[N];
int dist[N];
int n, m;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[1] = 0;
    heap.push({dist[1], 1});

    while(heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.y;
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

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof(h));

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    dijkstra();

    if(dist[n] == INF) puts("-1");
    else cout << dist[n] << endl;

    return 0;
}