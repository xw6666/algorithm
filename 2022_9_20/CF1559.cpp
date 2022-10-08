#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first 
#define y second
const int N = 1e5 + 10;
// bool st[N][N];
int p1[N];
int p2[N];

int find(int x, int *p) {
    if(x != p[x]) p[x] = find(p[x], p);
    return p[x];
}

void solve() {
    int n, m, k;
    cin >> k >> n >> m;
    for(int i = 1;i <= k;i++) p1[i] = i;
    for(int i = 1;i <= k;i++) p2[i] = i;

    for(int i = 1;i <= n;i++) {
        int a, b;
        cin >> a >> b;
        a = find(a, p1);
        b = find(b, p1);    
        p1[a] = b;
    }

    for(int i = 1;i <= m;i++) {
        int a, b;
        cin >> a >> b;
        a = find(a, p2);
        b = find(b, p2);
        p2[a] = b;
    }

    vector<PII> ans;
    for(int i = 1;i <= k;i++) {
        for(int j = 1;j < i;j++) {
            int a1 = find(i, p1), b1 = find(j, p1);
            int a2 = find(i, p2), b2 = find(j, p2);
            if(a1 != b1 && a2 != b2) {
                p1[a1] = b1;
                p2[a2] = b2;
                ans.push_back({i, j}); 
            }
        }
    }


    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++) cout << ans[i].x << " " << ans[i].y << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt = 1 ;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}