#include <bits/stdc++.h>
using namespace std;

const int N = 6010;
int p[N], sz[N];
int n;
struct Edge {
    int a, b, w;
    bool operator< (const Edge& t) const {
        return w < t.w;
    }
}e[N];

int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void solve() {
    cin >> n;
    for(int i = 1;i <= n;i++) p[i] = i, sz[i] = 1;

    for(int i = 0;i < n - 1;i++) {
        cin >> e[i].a >> e[i].b >> e[i].w;
    }

    sort(e, e + n - 1);

    int ans = 0;
    for(int i = 0;i < n - 1;i++) {
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;

        if(a != b) {
            ans += (sz[a] * sz[b] - 1) * (w + 1);
            p[a] = b;
            sz[b] += sz[a];
        }
    }

    cout << ans << endl;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}