#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 2 * N;

int h[N], e[M], ne[M], idx;
int n;
int f[N][3];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u, int ls) {
    f[u][0] = 0;
    f[u][1] = 1;
    f[u][2] = 0;
    int t = 0;

    for(int i = h[u];~i;i = ne[i]) {
        int j = e[i];
        if(j == ls) continue;
        dfs(j, u);

        f[u][0] += max(f[j][0], max(f[j][1], f[j][2]));
        f[u][1] += f[j][0];
    }



    for(int i = h[u];~i;i = ne[i]) {
        int j = e[i];
        if(j == ls) continue;
        t = max(t, f[u][1] - f[j][0] + f[j][1]);
    }

    f[u][2] = t;
}

void solve() {
    cin >> n;
    idx = 0;
    for(int i = 1;i <= n;i++) h[i] = -1;

    for(int i = 0;i < n - 1;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    dfs(1, -1);

    cout << max(f[1][0], max(f[1][1], f[1][2])) << endl;
}

int main() {
    int size(512<<20);  // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    int tt;
    cin >> tt;
    while(tt--) solve();

    exit(0);
}