#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

LL check(LL a, LL b)
{
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

int main()
{
    LL n;
    cin >> n;
    LL ans = 1e18;
    
    for(LL i = 0;i <= 1000000;i++)
    {
        LL l = i, r = 1000000;
        while(l < r)
        {
            LL mid = l + r >> 1;
            if(check(i, mid) >= n) r = mid;
            else l = mid + 1;
        }
        ans = min(ans, check(i, r));
    }
    
    cout << ans << endl;
    
    return 0;
}


