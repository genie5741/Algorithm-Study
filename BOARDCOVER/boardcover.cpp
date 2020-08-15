#include <bits/stdc++.h>
using namespace std;

int C, H, W;

int coverType[5][4][3] = {
    { {0, 0}, {1, 0}, {0, 1} },
    { {0, 0}, {0, 1}, {1, 1} },
    { {0, 0}, {1, 0}, {1, 1} },
    { {0, 0}, {1, 0}, {1, -1} }
};

bool on(vector<vector<int>>& board, int y, int x, int type, int delta) {
    bool ok = 1;

    for(int i=0; i<3; i++) {
        int ny = y + coverType[type][i][0];
        int nx = x + coverType[type][i][1];

        if(ny < 0 || ny >= H || nx < 0 || nx >= W) ok = 0;
        else if((board[ny][nx] += delta) > 1) ok = 0;
    }

    return ok;
}

int cover(vector<vector<int>>& board) {
    int y = -1, x = -1;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(!board[i][j]) {
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1) break;
    }

    if(y == -1) return 1;
    
    int res = 0;
    for(int type=0; type<4; type++) {
        if(on(board, y, x, type, 1))
            res += cover(board);
        
        on(board, y, x, type, -1);
    }

    return res;
}

int main() {
    scanf("%d", &C);

    char tmp;

    while(C--) {
        vector<vector<int>> board(21, vector<int>(21, 0));

        scanf("%d %d", &H, &W);
        
        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                scanf(" %c", &tmp);
                if(tmp == '#') 
                    board[i][j] = 1;
            }
        }

        printf("%d\n", cover(board));
    }

    return 0;
}