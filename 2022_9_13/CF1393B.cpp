#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int a[N];
int n, q;
int cnt1, cnt2;

int main() {
    cin >> n;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        cnt1 -= a[x] / 4;
        cnt2 -= a[x] / 2;
        a[x]++;
        cnt1 += a[x] / 4;
        cnt2 += a[x] / 2;
    }

    cin >> q;
    while(q--) {
        char op[2];
        scanf("%s", op);
        int x;
        cin >> x;
        cnt1 -= a[x] / 4;
        cnt2 -= a[x] / 2;
        if(op[0] == '+') a[x]++;
        else a[x]--;
        cnt1 += a[x] / 4;
        cnt2 += a[x] / 2;

        if(cnt1 >= 1 && cnt2 >= 4) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}