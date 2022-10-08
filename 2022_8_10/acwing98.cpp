#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
#define x first 
#define y second

PLL get(int n, LL m) {
    if(n == 0) return {0, 0};
    LL block = (LL)1 << (2 * n - 2);
    LL len = (LL)1 << (n - 1);
    
    auto p = get(n - 1, m % block);
    LL t = m / block;

    LL x = p.x, y = p.y;

    if(t == 0) return {y, x};
    else if(t == 1) return {x, y + len};
    else if(t == 2) return {x + len, y};

    return {2 * len - y, len - x};
}

void solve() {
    LL n, a, b;
    cin >> n >> a >> b;
    auto p1 = get(n, a - 1);
    auto p2 = get(n, b - 1);
    LL x = p1.x - p2.x;
    LL y = p1.y - p2.y;
    double t = sqrt(x * x + y * y) * 10;
    printf("%.0lf\n", t);
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}