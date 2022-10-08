#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1010, M = 10010, INF = 0x3f3f3f3f;
int h[N], e[M], ne[M], w[M], idx;
int dist[N][2], cnt[N][2];
bool st[N][2];
int n, m;
int s, t;

struct Node {
    int id, type, distance;
    bool operator> (const Node& a) const {
        return distance > a.distance;
    }
};

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    memset(st, 0, sizeof(st));
    
    dist[s][0] = 0;
    cnt[s][0] = 1;
    priority_queue<Node, vector<Node>, greater<Node>> heap;
    heap.push({s, 0, 0});

    while(heap.size()) {
        auto t = heap.top();
        heap.pop();

        int id = t.id, type = t.type, distance = t.distance;
        if(st[id][type]) continue;
        st[id][type] = true;

        for(int i = h[id];~i;i = ne[i]) {
            int j = e[i];

            if(dist[j][0] > dist[id][type] + w[i]) {
                dist[j][1] = dist[j][0];
                cnt[j][1] = cnt[j][0];
                heap.push({j, 1, dist[j][1]});
                dist[j][0] = dist[id][type] + w[i];
                cnt[j][0] = cnt[id][type];
                heap.push({j, 0, dist[j][0]});
            } else if(dist[j][0] == dist[id][type] + w[i]) cnt[j][0] += cnt[id][type];
            else if(dist[j][1] > dist[id][type] + w[i]) {
                dist[j][1] = dist[id][type] + w[i];
                cnt[j][1] = cnt[id][type];
                heap.push({j, 1, dist[j][1]});
            } else if(dist[j][1] == dist[id][type] + w[i]) cnt[j][1] += cnt[id][type];
        }
    }
    
}

void solve() {
    cin >> n >> m;
    idx = 0;
    for(int i = 1;i <= n;i++) h[i] = -1;

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cin >> s >> t;
    dijkstra();
    
    int ans = cnt[t][0];

    if(dist[t][0] - dist[t][1] == -1) ans += cnt[t][1];
    
    cout << ans << endl;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}