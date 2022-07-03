#include <iostream>
using namespace std;
typedef long long LL;

int n;
LL C(int a, int b)
{
    LL ans = 1;
    for(int i = a,j = 1;j <= b;j++,i--)
    {
        ans = ans * i / j;
        if(ans > n) break;
    }

    return ans;
}

bool check(int k)
{
    int l = 2 * k, r = n;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(C(mid, k) >= n) r = mid;
        else l = mid + 1;
    }  

    if(C(r, k) != n) return false;

    cout << (LL)(r + 1) * r / 2 + k + 1 << endl;
    return true;
}

int main()
{
    cin >> n;
    for(int k = 16;;k--)
    {
        if(check(k)) break;
    }


    return 0;
}