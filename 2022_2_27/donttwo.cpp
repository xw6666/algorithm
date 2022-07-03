#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N];

int dx[] = {0, -2, 0, 2}, dy[] = {2, 0, -2, 0};

int main()
{
    int ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                ans++;
                for (int k = 0; k < 4; k++)
                {
                    int tx = dx[k] + i;
                    int ty = dy[k] + j;
                    if (!(tx >= 0 && tx < n && ty >= 0 && ty < m))
                        continue;
                    a[tx][ty] = -1;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}