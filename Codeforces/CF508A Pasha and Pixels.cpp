#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

bool board[MAXN][MAXN];

int main() {
    int n, m, k;
    int r, c;
    ios::sync_with_stdio(false);
    while (cin >> n >> m >> k) {
        memset(board, false, sizeof(board));
        bool finished = false;
        for (int i = 1; i <= k; ++i) {
            cin >> r >> c;
            board[r][c] = true;
            if (!finished) {
                if ((board[r - 1][c - 1] and board[r - 1][c] and board[r][c - 1]) or
                    (board[r + 1][c - 1] and board[r + 1][c] and board[r][c - 1]) or
                    (board[r - 1][c + 1] and board[r - 1][c] and board[r][c + 1]) or
                    (board[r + 1][c + 1] and board[r + 1][c] and board[r][c + 1])) {
                    finished = true;
                    cout << i << endl;
                }
            }
        }
        if (!finished) {
            cout << 0 << endl;
        }
    }
    return 0;
}
