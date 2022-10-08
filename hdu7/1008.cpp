#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--, b--, c--;

    int ans = (a ^ b ^ c);
    if(ans) cout << "Win" << endl;
    else cout << "Lose" << endl;
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}