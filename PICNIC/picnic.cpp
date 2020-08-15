#include <bits/stdc++.h>
using namespace std;

bool areFriends[11][11];
bool taken[11];
int c, n, m;

int countPairings(bool taken[]) {
    int ptr = -1;

    for(int i=0; i<n; i++) {
        if(!taken[i]) {
            ptr = i;
            break;
        }
    }

    if(ptr == -1) return 1;

    int res = 0;
    for(int i=ptr; i<n; i++) {
        if(!taken[i] && areFriends[i][ptr]) {
            taken[ptr] = taken[i] = 1;
            res += countPairings(taken);
            taken[ptr] = taken[i] = 0;
        }
    }

    return res;
}

int main() {
    scanf("%d", &c);

    while(c--) {
        memset(areFriends, 0, sizeof(areFriends));
        memset(taken, 0, sizeof(taken));

        scanf("%d %d", &n, &m);

        int tmp1, tmp2;
        for(int i=0; i<m; i++) {
            scanf("%d %d", &tmp1, &tmp2);
            areFriends[tmp1][tmp2] = areFriends[tmp2][tmp1] = 1;
        }
        
        printf("%d\n", countPairings(taken));
    }

    return 0;
}
