#include <bits/stdc++.h>
using namespace std;

int getmin(int a, int b, int c, int d) {
    if(b || c) d = 0;
    else {
        if(d) d = 1;
    }
    int t = min(b, c);
    a += t, b -= t , c -= t;

    return a + b + c + d;
}

int getmax(int a, int b, int c, int d) {
    int ans = 0;
    if(a) {
        ans += 1 + b + c;
        a--;
        if(d <= 2) {
            ans += a + d;
            return ans;
        } else {
            ans += 2;
            d -= 2;
            int t = min(a, d);
            ans += 2 * t, a -= t, d -= t;
            if(a) ans += a;
            return ans;
        }
    } else {
        ans += b + c;
        if(d) ans ++;
        return ans;
    }
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    cout << getmin(a, b, c, d) << " " << getmax(a, b, c, d) << endl;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}