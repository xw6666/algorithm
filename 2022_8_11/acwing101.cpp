#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
typedef pair<int, int> PII;
int a[N];
map<PII, bool> st;
int n, p, h, m;

void add(int l, int r, int c) {
    a[l] += c;
    a[r + 1] -= c;
}

int main() {
    cin >> n >> p >> h >> m;

    for(int i = 0;i < m;i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        if(l > r) swap(l, r);
        if(!st[make_pair(l, r)]) {
            add(l + 1, r - 1, -1);
            st[make_pair(l, r)] = true;
        }
    }

    for(int i = 1;i <= n;i++) a[i] += a[i - 1];

    for(int i = 1;i <= n;i++) cout << a[i] + h << endl;

    return 0;
}