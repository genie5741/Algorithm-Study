#include <bits/stdc++.h>
using namespace std;

string reverseQuadtree(string::iterator& iter) {
    char head = *iter;
    iter++;

    if(head == 'b' || head == 'w')
        return string(1, head);
    
    string upperLeft = reverseQuadtree(iter);
    string upperRight = reverseQuadtree(iter);
    string lowerLeft = reverseQuadtree(iter);
    string lowerRight = reverseQuadtree(iter);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    cin >> C;
    
    string str;
    while(C--) {
        cin >> str;
        string::iterator iter = str.begin();
        cout << reverseQuadtree(iter) << '\n';
    }

    return 0;
}   