#include <bits/stdc++.h>
using namespace std;
const int STEP_X[] = {1, 1, -1, -1};
const int STEP_Y[] = {1, -1, 1, -1};

void dfs(vector<string> &apart, int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int tx = x + STEP_X[i];
        int ty = y + STEP_Y[i];
        if (tx >= 0 && tx < apart.size()) {
            if (ty >= 0 && ty < apart[x].size()) {
                if (apart[tx][ty] == '*' && apart[tx][y] == '.' && apart[x][ty] == '.') {
                    apart[tx][ty] = '.';
                    dfs(apart, tx, ty);
                } else if (apart[tx][ty] == '.' && apart[tx][y] == '*' && apart[x][ty] == '.') {
                    apart[tx][y] = '.';
                    dfs(apart, tx, y);
                } else if (apart[tx][ty] == '.' && apart[tx][y] == '.' && apart[x][ty] == '*') {
                    apart[x][ty] = '.';
                    dfs(apart, x, ty);
                }
            }
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<string> apart(n);
        for (int i = 0; i < n; ++i) {
            cin >> apart[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (apart[i][j] == '.') {
                    dfs(apart, i, j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << apart[i] << endl;
        }
    }
    return 0;
}
