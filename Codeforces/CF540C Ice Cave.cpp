#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;
const int DIR_X[] = {1, 0, -1, 0};
const int DIR_Y[] = {0, 1, 0, -1};

int n, m;
char cave[MAXN][MAXN];
int sx, sy, ex, ey;

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            cin >> (cave[i] + 1);
        }
        cin >> sx >> sy;
        cin >> ex >> ey;
        queue<pair<int, int>> que;
        que.push(pair<int, int>(sx, sy));
        bool could = false;
        while (not que.empty() and not could) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for (int k = 0; k < 4; ++k) {
                int tx = x + DIR_X[k];
                int ty = y + DIR_Y[k];
                if (1 <= tx and tx <= n) {
                    if (1 <= ty and ty <= m) {
                        if (tx == ex and ty == ey and cave[tx][ty] == 'X') {
                            could = true;
                            break;
                        } else if (cave[tx][ty] == '.') {
                            cave[tx][ty] = 'X';
                            que.push(pair<int, int>(tx, ty));
                        }
                    }
                }
            }
        }
        cout << (could ? "YES" : "NO") << endl;
    }
    return 0;
}
