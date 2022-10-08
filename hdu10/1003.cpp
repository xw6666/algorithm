#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef long long LL;
int a[N];
int b[N];
int n;

bool check(int a[]) {
    bool flag = true;
    for(int i = 1;i <= n;i++) {
        if(i == 1) {
            if(!(a[i] < a[i + 1] || a[i] > a[i + 1])) {
                flag = false;
                break;
            }
        } else if(i == n) {
            if(!(a[i] < a[i - 1] || a[i] > a[i - 1])) {
                flag = false;
                break;
            }
        } else {
            if(!((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))) {
                flag = false;
                break;
            }
        }
    }

    return flag;
}

void solve() {
    cin >> n;
    if(n == 1) {
        printf("0\n");
        return;
    }

    for(int i = 1;i <= n;i++) scanf("%d",a + i), b[i] = a[i];

    LL res = 1e18;
    LL ans = 0;
    bool flag = true;
    for(int i = 2;i <= n;i++) {
        if(flag) {
            if(a[i] <= a[i - 1]) {
                ans += a[i - 1] - a[i] + 1;
                a[i] = a[i - 1] + 1;
            }
            flag = false;
        } else {
            if(a[i] >= a[i - 1]) {
                if(a[i] == 1 || a[i - 1] == 1) continue;
                ans += a[i] - a[i - 1] + 1;
                a[i] = a[i - 1] - 1;
            }
            flag = true;
        }
    }

    if(check(a)) res = min(res, ans);
    flag = false;
    ans = 0;
        for(int i = 2;i <= n;i++) {
        if(flag) {
            if(b[i] <= b[i - 1]) {
                ans += b[i - 1] - b[i] + 1;
                b[i] = b[i - 1] + 1;
            }
            flag = false;
        } else {
            if(b[i] >= b[i - 1]) {
                if(b[i] == 1 || b[i - 1] == 1) continue;
                ans += b[i] - b[i - 1] + 1;
                b[i] = b[i - 1] - 1;
            }
            flag = true;
        }
    }


    if(check(b)) res = min(res, ans);

    cout << res << endl;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}