#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second;

const int N = 55;
int a[N];
int b[N];

void solve() {
    int n;
    cin >> n;
    LL sum = 0;
    for(int i = 0;i < n;i++) cin >> a[i], sum += a[i];

    LL t = 0;
    for(int i = 0;i < n;i++) {
        if(i % 2 == 0) {
            b[i] = 1;
            t += abs(1 - a[i]);
        } else b[i] = a[i];
    }

    if(t * 2 <= sum) {
        // cout << "YES" << endl;
        for(int i = 0;i < n;i++) cout << b[i] << " ";
        cout << endl;
    } else {
        t = 0;
        for(int i = 0;i < n;i++) {
            if(i % 2 == 0) b[i] = a[i];
            else b[i] = 1, t += abs(1 - a[i]);
        } 

        if(t * 2 <= sum) {
            for(int i = 0;i < n;i++) cout << b[i] << " ";
                cout << endl;
        }
    }
}

int main() {
    int tt;
    cin >> tt;
    while(tt--) solve();

    return 0;
}