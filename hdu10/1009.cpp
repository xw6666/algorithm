#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int b[]={0,1,1,2,2,3,3,3};
int a[]={0,1,1,1,2,2,3,3};

void solve() {
    int n;
    scanf("%d", &n);
    char op[100];
    scanf("%s", op);
    if(op[0] == 'A') {
        if(n <= 7) printf("%d\n", a[n]);
        else printf("%lld\n", ((LL)n / 7) * a[7] + a[n % 7]);
    } else {
        if(n <= 7) printf("%d\n", b[n]);
        else printf("%lld\n", ((LL)n / 7) * a[7] + b[n % 7]);
    }
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}