#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second

const int N = 152;
const double INF = 1e20;
int n;
double d[N][N], maxd[N];
char g[N][N];
PII q[N];

double get(PII a, PII b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;

    return sqrt(dx * dx + dy *dy);
}

void floyed() {
    for(int k = 0;k < n;k++) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0;i < n;i++)  cin >> q[i].x >> q[i].y;

    for(int i = 0;i < n;i++) cin >> g[i];
    

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(i == j) continue;
            if(g[i][j] == '1') d[i][j] = get(q[i], q[j]);
            else d[i][j] = INF;
        }
    }

    floyed();
    double ans1 = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(d[i][j] < INF / 2) maxd[i] = max(maxd[i], d[i][j]);
        }
        ans1 = max(ans1, maxd[i]);
    }



    double ans2 = INF;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(d[i][j] > INF / 2) ans2 = min(ans2, maxd[i] + maxd[j] + get(q[i], q[j]));

        }
    }
    

    printf("%.6lf\n", max(ans1, ans2));

    return 0;
}