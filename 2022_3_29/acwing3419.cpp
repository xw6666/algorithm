//暴力 - 超时
// #include <iostream>
// using namespace std;
// #include <algorithm>
// #include <cstring>

// using namespace std;

// const int N = 1e5 + 10;
// int a[N];

// bool cmp(int a,int b)
// {
//     return b < a;
// }

// int main()
// {
//     int n, q;
//     cin >> n >> q;
//     for(int i = 1;i <= n;i++) a[i] = i;

//     while(q--)
//     {
//         int op, d;
//         cin >> op >> d;
//         if(op == 0)
//         {
//             sort(a + 1, a + 1 + d, cmp);
//         }
//         else
//         {
//             sort(a + d, a + n + 1);
//         }
//     }

//     for(int i = 1;i <= n;i++) printf("%d ", a[i]);
//     cout << '\n';
    
//     return 0;
// }