#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N];
int n;

int main() {
    int n;
    cin >> n;
    int t = n / 2;
    int ans = 0;
    for(int i = 0;i < n;i++) scanf("%d", a + i);
    
    sort(a, a + n);

    for(int i = 0;i < n;i++) ans += abs(a[t] - a[i]);

    cout << ans << endl;

    return 0;
}