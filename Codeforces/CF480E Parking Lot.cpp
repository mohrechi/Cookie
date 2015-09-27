#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 10;

int n, m, k;
char board[MAXN][MAXN];
int dp[MAXN][MAXN], lef[MAXN][MAXN];
int up[MAXN][MAXN], dw[MAXN][MAXN];
struct Point {
    int x, y;
} car[MAXN];
int ans[MAXN];

struct TreeNode {
    int l, r, u, d;
} tree[MAXN * 3];

inline int lc(int x) {
    return x * 2;
}

inline int rc(int x) {
    return lc(x) + 1;
}

void build(int x, int row, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].u = up[row][l];
        tree[x].d = dw[row][r];
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), row, l, mid);
    build(rc(x), row, mid + 1, r);
    tree[x].u = min(tree[lc(x)].u, tree[rc(x)].u);
    tree[x].d = min(tree[lc(x)].d, tree[rc(x)].d);
}

pair<int, int> query(int x, int l, int r) {
    if (tree[x].l == l && tree[x].r == r) {
        return {tree[x].u, tree[x].d};
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (r <= mid) {
        return query(lc(x), l, r);
    }
    if (l > mid) {
        return query(rc(x), l, r);
    }
    auto ansL = query(lc(x), l, mid);
    auto ansR = query(rc(x), mid + 1, r);
    return {min(ansL.first, ansR.first), min(ansL.second, ansR.second)};
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", board[i] + 1);
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &car[i].x, &car[i].y);
        board[car[i].x][car[i].y] = 'X';
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (board[i][j] == 'X') {
                up[i][j] = 0;
                lef[i][j] = 0;
            } else {
                up[i][j] = up[i - 1][j] + 1;
                lef[i][j] = lef[i][j - 1] + 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (board[i][j] == '.') {
                dp[i][j] = min(dp[i - 1][j - 1] + 1, min(up[i][j], lef[i][j]));
                ans[k] = max(ans[k], dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            if (board[i][j] == 'X') {
                dw[i][j] = 0;
            } else {
                dw[i][j] = dw[i + 1][j] + 1;
            }
        }
    }
    for (int l = k - 1; l > 0; --l) {
        int x = car[l].x;
        int y = car[l].y;
        board[x][y] = '.';
        for (int i = 1; i <= n; ++i) {
            if (board[i][y] == 'X') {
                up[i][y] = 0;
            } else {
                up[i][y] = up[i - 1][y] + 1;
            }
        }
        for (int i = n; i >= 1; --i) {
            if (board[i][y] == 'X') {
                dw[i][y] = 0;
            } else {
                dw[i][y] = dw[i + 1][y] + 1;
            }
        }
        ans[l] = ans[l + 1];
        build(1, x, 1, m);
        for (int newSize = ans[l] + 1; newSize <= min(n, m); ++newSize) {
            bool found = false;
            for (int j = 1; j + newSize - 1 <= m; ++j) {
                auto minVal = query(1, j, j + newSize - 1);
                if (minVal.first + minVal.second - 1 >= newSize) {
                    found = true;
                    break;
                }
            }
            if (found) {
                ans[l] = newSize;
            } else {
                break;
            }
        }
    }
    for (int i = 1; i <= k; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
