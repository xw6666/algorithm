#include <bits/stdc++.h>
using namespace std;

const int N = 26;
int n, m;
int d[N][N], g[N][N];
bool st[N];

void floyed() {
    memcpy(d, g, sizeof(d));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            for(int k = 0;k < n;k++) d[i][j] |= d[i][k] && d[k][j];
        }
    }
}

int check() {
    for(int i = 0;i < n;i++) {
        if(d[i][i]) return 2;
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < i;j++) {
            if(!d[i][j] && !d[j][i]) return 0;
        }
    }

    return 1;
}

void get() {
    memset(st, 0, sizeof(st));
    for(int i = 0;i < n;i++) {
        if(!st[i]) {
            bool flag = true;
            for(int j = 0;j < n;j++) {
                if(!st[j] && d[j][i]) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                st[i] = true;
                printf("%c", i + 'A');
                return;
            }
        }
    }
}

void solve() {
    memset(g, 0, sizeof(g));
    memset(d, 0, sizeof(d));

    int i = 1;
    int type = 0;
    for(i = 1;i <= m;i++) {
        int a, b;
        scanf(" %c<%c", &a, &b);
        a -= 'A', b -= 'A';
        g[a][b] = 1;

        floyed(); 
        type = check();
        if(type) break;
    }
    
    
    if(!type) cout << "Sorted sequence cannot be determined." << endl;
    else if(type == 2) printf("Inconsistency found after %d relations.\n", i);
    else {
        printf("Sorted sequence determined after %d relations: ", i);

        for(int i = 0;i < n;i++) get();
        printf(".\n");
    }
    
    i++;
    while(i <= m) {
        int a, b;
        scanf(" %c<%c", &a, &b);
        i++;
    }
}

int main() {
    while(cin >> n >> m, n || m) solve();

    return 0;
}