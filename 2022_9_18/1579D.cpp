#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second

int n;

void solve() {
    priority_queue<PII, vector<PII>, less<PII>> heap;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        heap.push({x, i});
    }

    vector<PII> ans;
    while(heap.size() >= 2) {
        auto x = heap.top();
        heap.pop();
        auto y = heap.top();
        heap.pop();

        if(x.x && y.x) {
            x.x--;
            y.x--;
            ans.push_back({x.y, y.y});
            if(x.x) heap.push(x);
            if(y.x) heap.push(y);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++) cout << ans[i].x << " " << ans[i].y << endl;
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


