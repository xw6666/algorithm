#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
#define x first
#define y second
const int N = 1e5 + 10;
int n, m, s;
int a[N];

void solve() {
    cin >> n >> m >> s;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(int i = 1;i <= m;i++) heap.push({0, i});

    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        auto t = heap.top();
        heap.pop();
        t.x += x;
        a[i] = t.y;
        heap.push(t);
    }

    int minv = 2e9;
    int maxv = -1;
    while(heap.size()) {
        auto t = heap.top();
        heap.pop();
        minv = min(minv, t.x);
        maxv = max(maxv, t.x);
    }

    if(maxv - minv > s) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(int i = 0;i < n;i++) cout << a[i] << " ";
            cout << endl;
    }
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