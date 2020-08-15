#include <bits/stdc++.h>
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const bool linked[SWITCHES][CLOCKS+1] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 1 ,0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

int C;

bool areAligned(vector<int>& clocks) {
    bool flag = 1;
    for(int i=0; i<CLOCKS; i++) {
        if(clocks[i] != 12) {
            flag = 0;
            break;
        }
    }
    
    return flag;
}

void push(vector<int>& clocks, int switchNum) {
    for(int i=0; i<CLOCKS; i++) {
        if(linked[switchNum][i]) {
            clocks[i] += 3;
            if(clocks[i] == 15) clocks[i] = 3;
        }
    }
}

int solve(vector<int>& clocks, int switchNum) {
    if(switchNum == SWITCHES) return areAligned(clocks) ? 0 : INF;

    int res = INF;
    for(int cnt=0; cnt<4; cnt++) {
        res = min(res, cnt + solve(clocks, switchNum+1));
        push(clocks, switchNum);
    }

    return res;
}

int main() {
    scanf("%d", &C);
    
    while(C--) {
        int tmp;
        vector<int> clocks(CLOCKS+1, 0);
        for(int i=0; i<CLOCKS; i++) {
            scanf(" %d", &tmp);
            clocks[i] = tmp;
        }

        printf("%d\n", solve(clocks, 0));
    }

    return 0;
}