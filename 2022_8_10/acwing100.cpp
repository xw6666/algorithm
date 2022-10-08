#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef long long LL;

LL a[N];
LL b[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    LL p = 0, q = 0;
    b[1] = a[1];
    for(int i = 2;i <= n;i++) {
        b[i] = a[i] - a[i - 1];
        if(b[i] > 0) p += b[i];
        else q -=  b[i];
    }

    cout << max(p, q) << endl;
    cout << abs(p - q) + 1 << endl;

    return 0;
}