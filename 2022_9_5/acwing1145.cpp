#include <bits/stdc++.h>
using namespace std;
const int N = 550, M = N * N;
typedef pair<int, int> PII;
#define x first 
#define y second

struct Edge {
    int a, b;
    double w;
    bool operator< (const Edge& t) const {
        return w < t.w;
    }
}e[M];

int n, k;
PII q[N];
int p[N];

int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

double get(PII a, PII b) {
    double x = a.x - b.x;
    double y = a.y - b.y;
    return sqrt(x * x + y * y);
}

int main() {
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> q[i].x >> q[i].y;

    int cnt = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < i;j++) {
            double w = get(q[i], q[j]);
            e[cnt++] = {i, j, w};
        }
    }

    sort(e, e + cnt);
    for(int i = 0;i < n;i++) p[i] = i;
    

    double ans = 0;
    int cur = n;
    for(int i = 0;i < cnt;i++) {
        if(cur <= k) break;

        int a = find(e[i].a), b = find(e[i].b);
        double w = e[i].w;
        if(a != b) {
            ans = w;
            p[a] = b;
            cur--;
        }
    }

    printf("%.2lf\n", ans);

    return 0;
}#include <bits/stdc++.h>
using namespace std;
const int N = 550, M = N * N;
typedef pair<int, int> PII;
#define x first 
#define y second

struct Edge {
    int a, b;
    double w;
    bool operator< (const Edge& t) const {
        return w < t.w;
    }
}e[M];

int n, k;
PII q[N];
int p[N];

int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

double get(PII a, PII b) {
    double x = a.x - b.x;
    double y = a.y - b.y;
    return sqrt(x * x + y * y);
}

int main() {
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> q[i].x >> q[i].y;

    int cnt = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < i;j++) {
            double w = get(q[i], q[j]);
            e[cnt++] = {i, j, w};
        }
    }

    sort(e, e + cnt);
    for(int i = 0;i < n;i++) p[i] = i;
    

    double ans = 0;
    int cur = n;
    for(int i = 0;i < cnt;i++) {
        if(cur <= k) break;

        int a = find(e[i].a), b = find(e[i].b);
        double w = e[i].w;
        if(a != b) {
            ans = w;
            p[a] = b;
            cur--;
        }
    }

    printf("%.2lf\n", ans);

    return 0;
}