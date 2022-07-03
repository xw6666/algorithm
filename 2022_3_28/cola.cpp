#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    while (cin >> a >> b >> c, !(a == 0 && b == 0 && c == 0))
    {
        int ans = 0;
        if(b < c) swap(b, c);
        int x = a,y = 0,z = 0;
        bool flag = true;
        while(x > 0)
        {
            x -= c;
            y += c;
            ans++;
            if(x == y) break;
            if(y >= b)
            {
                flag = false;
                break;
            }
        }
        
    }
    return 0;
}