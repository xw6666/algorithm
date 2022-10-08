#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 2000010;
int hs[N], ht[N], e[M], ne[M], idx;
int w[N];
int mink[N], maxk[N];
bool st[N];
int n, m;

void add(int h[], int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void spfa1() {
    memset(mink, 0x3f, sizeof(mink));
    memset(st, 0, sizeof(st));
    mink[1] = w[1];
    queue<int> q;
    q.push(1);
    st[1] = true;

    while(q.size()) {
        int t = q.front();
        q.pop();

        st[t] = false;

        for(int i = hs[t];~i;i = ne[i]) {
            int j = e[i];
            if(mink[j] > min(mink[t], w[j])) {
                mink[j] = min(mink[t], w[j]);
                
                if(!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

void spfa2() {
    memset(st, 0, sizeof(st));
    memset(maxk, 0xcf, sizeof(maxk));
    maxk[n] = w[n];
    queue<int> q;
    q.push(n);
    st[n] = true;

    while(q.size()) {
        int t = q.front();
        q.pop();

        st[t] = false;

        for(int i = ht[t];~i;i = ne[i]) {
            int j = e[i];
            // cout << t << " " << j << endl;
            if(maxk[j] < max(maxk[t], w[j])) {
                maxk[j] = max(maxk[t], w[j]);
                
                if(!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main() {
    memset(hs, -1, sizeof(hs));
    memset(ht, -1, sizeof(ht));

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> w[i];

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(hs, a, b);
        add(ht, b, a);
        if(c == 2) {
            add(hs, b, a);
            add(ht, a, b);
        }
    }

    spfa1();
    spfa2();

    // for(int i = 1;i <= n;i++) cout << i << " " << mink[i] << " " << maxk[i] << endl;

    int ans = 0;
    for(int i = 1;i <= n;i++) ans = max(ans, maxk[i] - mink[i]);

    cout << ans << endl;

    return 0;
}