#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 10;
const int DIR_X[] = {0, 1, 0, -1};
const int DIR_Y[] = {1, 0, -1, 0};

int n, m;
char grid[MAXN][MAXN];

queue<pair<int, int>> pos;

void tryAdd(int x, int y) {
    if (grid[x][y] == '.') {
        int degree = 0;
        for (int k = 0; k < 4; ++k) {
            int tx = x + DIR_X[k];
            int ty = y + DIR_Y[k];
            if (0 <= tx && tx < n) {
                if (0 <= ty && ty < m) {
                    if (grid[tx][ty] == '.') {
                        ++degree;
                    }
                }
            }
        }
        if (degree == 1) {
            pos.push(pair<int, int>(x, y));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        pos = queue<pair<int, int>>();
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                tryAdd(x, y);
            }
        }
        bool isUnique = true;
        while (!pos.empty()) {
            pair<int, int> p = pos.front();
            pos.pop();
            int x = p.first;
            int y = p.second;
            if (grid[x][y] != '.') {
                continue;
            }
            int tx, ty;
            for (int k = 0; k <= 4; ++k) {
                if (k == 4) {
                    isUnique = false;
                    break;
                }
                tx = x + DIR_X[k];
                ty = y + DIR_Y[k];
                if (0 <= tx && tx < n) {
                    if (0 <= ty && ty < m) {
                        if (grid[tx][ty] == '.') {
                            break;
                        }
                    }
                }
            }
            if (!isUnique) {
                break;
            }
            if (tx == x + 1) {
                grid[x][y] = '^';
                grid[tx][ty] = 'v';
            } else if (tx == x - 1) {
                grid[tx][ty] = '^';
                grid[x][y] = 'v';
            } else if (ty == y + 1) {
                grid[x][y] = '<';
                grid[tx][ty] = '>';
            } else if (ty == y - 1) {
                grid[tx][ty] = '<';
                grid[x][y] = '>';
            }
            x = tx;
            y = ty;
            for (int k = 0; k < 4; ++k) {
                tx = x + DIR_X[k];
                ty = y + DIR_Y[k];
                if (0 <= tx && tx < n) {
                    if (0 <= ty && ty < m) {
                        tryAdd(tx, ty);
                    }
                }
            }
        }
        for (int i = 0; i < n && isUnique; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '.') {
                    isUnique = false;
                    break;
                }
            }
        }
        if (isUnique) {
            for (int i = 0; i < n; ++i) {
                cout << grid[i] << endl;
            }
        } else {
            cout << "Not unique" << endl;
        }
    }
    return 0;
}
