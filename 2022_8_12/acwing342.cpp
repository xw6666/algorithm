#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 25010, M = 150010, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
int n, mr, ml, S;
int dist[N];
bool st[N];
int id[N], cnt;
int d[N];
vector<int> block[N];
queue<int> q;

void add(int a, int b, int c) {
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u, int bid) {
    id[u] = bid;
    block[bid].push_back(u);

    for(int i = h[u];~i;i = ne[i]) {
        int j = e[i];
        if(!id[j]) {
            dfs(j, bid);
        }
    }
}

void dijkstra(int bid) {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(auto& e : block[bid]) heap.push({dist[e], e});

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
                if(id[j] == id[ver]) heap.push({dist[j], j});
            }

            if(id[j] != id[ver]) {
                d[id[j]]--;
                if(!d[id[j]]) q.push(id[j]);
            }
        }
    }
}

void top() {
    memset(dist, 0x3f, sizeof(dist));
    dist[S] = 0;

    for(int i = 1;i <= cnt;i++) {
        if(!d[i]) q.push(i);
    }

    while(q.size()) {
        int t = q.front();
        q.pop();

        dijkstra(t);
    }
}

int main() {
    cin >> n >> mr >> ml >> S;
    memset(h, -1, sizeof(h));

    while(mr--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a ,c);
    }

    for(int i = 1;i <= n;i++) {
        if(!id[i]) dfs(i, ++cnt);
    }

    while(ml--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        d[id[b]]++;
    }

    top();

    for(int i = 1;i <= n;i++) {
        if(dist[i] > INF / 2) cout << "NO PATH" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}