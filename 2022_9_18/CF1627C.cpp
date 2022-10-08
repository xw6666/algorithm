#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 2e5 + 10;
int d[N];
int h[N], e[N], ne[N], idx;
int n;


void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u, int ls, int v, int* w) {
    for(int i = h[u];~i;i = ne[i]) {
        int j = e[i];
        if(j == ls) continue;
        if(v == 2) w[i] = 3, v = 3;
        else w[i] = 2, v = 2;
        dfs(j, u, v, w);
    }
}

void solve() {
    idx = 0;
    cin >> n;
    int w[2 * n + 10] = {0};
    for(int i = 1;i <= n;i++) h[i] = -1;
    for(int i = 1;i <= n;i++) d[i] = 0;
    
    for(int i = 0;i < n - 1;i++) {
        int a, b;
        cin >> a >> b;

        d[a]++;
        d[b]++;
        add(a, b);
        add(b, a);
    }

    for(int i = 1;i <= n;i++) {
        if(d[i] > 2) {
            cout << -1 << endl;
            return;
        }
    }

    int root = 1;
    while(d[root] > 1) root++;

    dfs(root, -1, 2, w);
    for(int i = 0;i < idx;i++) {
        if(w[i]) cout << w[i] << " ";
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}


