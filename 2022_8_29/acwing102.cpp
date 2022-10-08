#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const double eps = 1e-5;
double a[N], s[N];
int n, f;

bool check(double t) {
    for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i] - t;

    double mins = 1e9;
    for(int i = f, j = 0;i <= n;i++, j++) {
        mins = min(mins, s[j]);
        if(s[i] - mins >= 0) return true;
    }

    return false;
}

int main() {
    cin >> n >> f;
    double l = 0, r = 0;
    for(int i = 1;i <= n;i++) cin >> a[i], r = max(r, a[i]);

    while(r - l > eps) {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    } 

    printf("%d\n",  (int)(r * 1000));

    return 0;
}