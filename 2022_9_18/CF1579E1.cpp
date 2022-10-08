#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
int n;

void solve() {
    cin >> n;
    deque<int> q;

    while(n--) {
        int x;
        cin >> x;
        if(!q.size() || q.front() > x) q.push_front(x);
        else q.push_back(x);
    }

    while(q.size()) {
        int t = q.front();
        q.pop_front();
        cout << t << " ";
    }
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


