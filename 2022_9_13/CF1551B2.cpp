#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 2e5 + 10;
int a[N], k;
int cnt[N];
int n;

void solve() {
    vector<PII> v;
    cin >> n >> k;
    for(int i = 0;i <= n;i++) cnt[i] = 0, a[i] = 0;

    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        cnt[x]++;
        if(cnt[x] <= k) v.push_back({x, i});
    }


    sort(v.begin(), v.end());

    int gap = v.size() / k;
    for(int i = 0;i < gap;i++) {
        for(int j = 0;j < k;j++) a[v[i * k + j].y] = j + 1;
    }
    

    for(int i = 0;i < n;i++) cout << a[i] << " ";
        cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}

