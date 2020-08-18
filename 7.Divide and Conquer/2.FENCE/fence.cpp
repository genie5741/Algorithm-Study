#include <bits/stdc++.h>
using namespace std;

vector<int> h(20010, 0);

int solve(int left, int right) {
    if(left == right) return h[left];

    int mid = (left + right) / 2;

    int res = max(solve(left, mid), solve(mid+1, right));

    int lo = mid, hi = mid+1;
    int height = min(h[lo], h[hi]);

    res = max(res, height*2);

    while(left < lo || hi < right) {
        if(hi < right && (lo == left || h[lo-1] < h[hi+1])) {
            hi++;
            height = min(height, h[hi]);
        }
        else {
            lo--;
            height = min(height, h[lo]);
        }

        res = max(res, height*(hi-lo+1));
    }

    return res;
}

int main() {
    int C, N, tmp;
    scanf("%d", &C);

    while(C--) {
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            scanf(" %d", &tmp);
            h[i] = tmp;
        }

        printf("%d\n", solve(0, N));
    }

    return 0;
}