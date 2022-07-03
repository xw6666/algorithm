#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    int a[1001];
    memset(a,0,sizeof(a));
    for (int i = 0; i < 1000; i++)
        a[rand() % 100]++;

    for (int i = 0; i < 100; i++)
    {
        printf("%d 出现的次数为：%d次\n", i, a[i]);
    }
    return 0;
}