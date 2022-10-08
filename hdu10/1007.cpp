#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10, M = 2 * N, MOD = 998244353;
int h[N], e[M], ne[M], idx;
int sz[N], fa[N];
int f[N];
int n;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void get(int u, int ls) {
    sz[u] = 1;
    // fa[u] = 0;
    for(int i = h[u];~i;i = ne[i]) {
        int j = e[i];
        if(j == ls) continue;
        get(j, u);
        sz[u] += sz[j];
    }
    // fa[u] = n - son[u] - 1;
}

int qmi(int a, int b, int p) {
    int ans = 1;
    while(b) {
        if(b & 1)ans = (LL)ans * a % p;
        b >>= 1;
        a = (LL)a * a % p;
    }

    return ans;
}

void dfs(int u, int ls) {
    f[u] = 0;
    for(int i = h[u];~i;i = ne[i]) {
        int j = e[i];
        if(j == ls) continue;
        dfs(j, u);
        f[u] = ((LL)f[u] + f[j]) % MOD;
        if(sz[j] % 2 == 0) f[u] = ((LL)f[u] + 1) % MOD;
    }

}

void solve() {
    cin >> n;
    for(int i = 0;i <= n;i++) h[i] = -1;
    idx = 0;

    for(int i = 0;i < n - 1;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    get(1, -1);

    dfs(1, -1);

    cout << qmi(2, f[1], MOD) - 1 << endl;
}

int main() {
    int tt;
    cin >> tt; 
    while(tt--) solve();

    return 0;
}