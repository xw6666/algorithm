#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 110, INF = 0x3f3f3f3f;

int d[N][N], p[N][N], g[N][N];
int n, m;
vector<int> a;

void get(int i, int j) {
    if(p[i][j] == 0) return;

    int k = p[i][j];
    get(i, k);
    a.push_back(k);
    get(k, j);
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    for(int i = 1;i <= n;i++) g[i][i] = 0;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    memcpy(d, g, sizeof(g));


    int ans = INF;
    for(int k = 1;k <= n;k++) {

        for(int i = 1;i < k;i++) {
            for(int j = i + 1;j < k;j++) {
                if((LL)d[i][j] + g[k][i] + g[j][k] < ans) {
                    ans = d[i][j] + g[k][i] + g[j][k];
                    a.clear();
                    a.push_back(j);
                    get(i, j);
                    a.push_back(i);
                    a.push_back(k);                }
            }
        }

        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k;
                }
            }
        }
    }

    if(ans == INF) cout << "No solution." << endl;
    else {
        for(int i = 0;i < a.size();i++) cout << a[i] << " ";
            cout << endl;
    }

    return 0;
}