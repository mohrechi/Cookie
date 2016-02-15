#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;
const int DIR_X[] = {0, 1, 0, -1};
const int DIR_Y[] = {1, 0, -1, 0};

int n, m;
char board[MAXN][MAXN];
bool visit[MAXN][MAXN];
int parent[MAXN * MAXN];
int size[MAXN * MAXN];

void init() {
    int total = n * m;
    for (int i = 0; i < total; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void combine(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    parent[x] = y;
    size[y] += size[x];
    size[x] = 0;
}

int encode(int x, int y) {
    return x * m + y;
}

void dfs(int x, int y, int p) {
    visit[x][y] = true;
    combine(encode(x, y), p);
    for (int k = 0; k < 4; ++k) {
        int tx = x + DIR_X[k];
        int ty = y + DIR_Y[k];
        if (0 <= tx && tx < n) {
            if (0 <= ty && ty < m) {
                if (board[tx][ty] == '.' && !visit[tx][ty]) {
                    dfs(tx, ty, p);
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", board[i]);
    }
    init();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == '.' && !visit[i][j]) {
                dfs(i, j, encode(i, j));
            }
        }
    }
    set<int> fields;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == '*') {
                fields.clear();
                for (int k = 0; k < 4; ++k) {
                    int ti = i + DIR_X[k];
                    int tj = j + DIR_Y[k];
                    if (0 <= ti && ti < n) {
                        if (0 <= tj && tj < m) {
                            if (board[ti][tj] == '.') {
                                fields.insert(find(encode(ti, tj)));
                            }
                        }
                    }
                }
                board[i][j] = 1;
                for (auto field : fields) {
                    board[i][j] += size[field] % 10;
                }
                board[i][j] = board[i][j] % 10 + '0';
            }
        }
        puts(board[i]);
    }
    return 0;
}
