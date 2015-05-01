#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;

int n;
char board[MAXN][MAXN];
bool moves[MAXN * 2][MAXN * 2];

int main() {
    while (cin >> n) {
        vector<pair<int, int>> chesses;
        vector<pair<int, int>> empties;
        vector<pair<int, int>> occupies;
        for (int i = 0; i < n; ++i) {
            cin >> board[i];
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'o') {
                    chesses.push_back(pair<int, int>(i, j));
                } else if (board[i][j] == '.') {
                    empties.push_back(pair<int, int>(i, j));
                } else {
                    occupies.push_back(pair<int, int>(i, j));
                }
            }
        }
        bool possible = true;
        memset(moves, true, sizeof(moves));
        for (auto chess : chesses) {
            for (auto empty : empties) {
                moves[MAXN + empty.first - chess.first][MAXN + empty.second - chess.second] = false;
            }
        }
        for (auto occupy : occupies) {
            bool found = false;
            for (auto chess : chesses) {
                if (moves[MAXN + occupy.first - chess.first][MAXN + occupy.second - chess.second]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << "YES" << endl;
            for (int i = MAXN - n + 1; i <= MAXN + n - 1; ++i) {
                for (int j = MAXN - n + 1; j <= MAXN + n - 1; ++j) {
                    if (i == MAXN && j == MAXN) {
                        putchar('o');
                    } else {
                        putchar(moves[i][j] ? 'x' : '.');
                    }
                }
                putchar('\n');
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
