#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 2e5 + 10, B = M / 2;

bool f[N][M];
int w[N];
int n,sum;

int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) scanf("%d", w + i), sum += w[i];

    f[0][B] = true;
    for(int i = 1;i <= n;i++)
    {
        for(int j = -sum;j <= sum;j++)
        {
            f[i][j + B] |= f[i - 1][j + B];
            if(j - w[i] >= -sum) f[i][j + B] |= f[i - 1][j - w[i] + B];
            if(j + w[i] <= sum) f[i][j + B] |= f[i - 1][j + w[i] + B];
        }       
    }

    int ans = 0;
    for(int i = 1;i <= sum;i++) 
    {
        if(f[n][i + B]) ans ++;
    }

    cout << ans << endl;
    
    return 0;
}