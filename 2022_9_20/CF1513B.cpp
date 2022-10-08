#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define x first
#define y second
const int MOD = 1e9 + 7;
int n;

    // ifstream ifs;
    // ofstream ofs;

LL fac(int n) {
    LL ans = 1;
    for(int i = 2;i <= n;i++) ans = (ans * i) % MOD;

    return ans;
}
void solve() {
    // ifs >> n;
    cin >> n;
    
    vector<int> a;
    int x;
    // ifs >> x;
    cin >> x;
    LL sum = x;
    a.push_back(x);
    for(int i = 0;i < n - 1;i++) {
        int x;
        // ifs >> x;
        cin >> x;
        a.push_back(x);
        sum &= x;
    }


    int cnt = 0;
    for(int i = 0;i < a.size();i++) {
        if(a[i] == sum) cnt++;
    }

    // ofs << (((LL)cnt * (cnt - 1)) % MOD * fac(n - 2)) % MOD << endl;  
    cout << (((LL)cnt * (cnt - 1)) % MOD * fac(n - 2)) % MOD << endl;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ifs.open("C:\\Users\\14810\\Desktop\\chou\\9.in", ios::in);
    // ofs.open("C:\\Users\\14810\\Desktop\\chou\\9.out", ios::out);
    int tt;
    // ifs >> tt;
    cin >> tt;
    while(tt--) solve();
    // ifs.close();
    // ofs.close();
    return 0;
}