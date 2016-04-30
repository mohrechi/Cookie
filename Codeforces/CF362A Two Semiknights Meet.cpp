#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, x1, y1, x2, y2;
    char board[8];
    cin >> t;
    while (t--) {
        bool first = true;
        for (int i = 0; i < 8; ++i) {
            cin >> board;
            for (int j = 0; j < 8; ++j) {
                if (board[j] == 'K') {
                    if (first) {
                        x1 = i;
                        y1 = j;
                        first = false;
                    }
                    else {
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
        if ((x1 - x2) % 4 == 0 && (y1 - y2) % 4 == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
