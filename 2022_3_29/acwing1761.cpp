#include <iostream>
using namespace std;

const int N = 2020, B =  N / 2;

bool g[N][N];

int main()
{
    int x1,y1,x2,y2;
    int ans = 0;
    for(int i = 0;i < 2;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1 + B;j < x2 + B;j++)
        {
            for(int k = y1 + B;k < y2 + B;k++) g[j][k] = true, ans++;
        }
    }

    cin >> x1 >> y1 >> x2 >> y2;
    x1 += B, x2 += B, y1 += B, y2 += B;
    for(int i = x1;i < x2;i++)
    {
        for(int j = y1;j < y2;j++)
        {
            if(g[i][j]) ans--;
        }
    }

    cout << ans << endl;

    return 0;
}