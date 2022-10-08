#include <bits/stdc++.h>
using namespace std;

int main() {
    srand((unsigned int)time(NULL));
    ofstream f;
    f.open("C:\\Users\\14810\\Desktop\\chou\\9.in", ios::out);

    f << 5000 << endl;
    int tt = 5000;
    // int s = 114514
    while(tt--) {
        f << 5 << endl;
        for(int i = 0;i < 5;i++) {
            // int t;
            int t = rand() % 1000000001;
            if(t > 20000) t = 0;
            f << t << " ";
        }
    }

    f.close();
 
    return 0;
}