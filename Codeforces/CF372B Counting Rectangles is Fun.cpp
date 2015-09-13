#include <bits/stdc++.h>
using namespace std;
const int MAXN = 40 + 3;

int n, m;
char board[MAXN][MAXN];
int sum[MAXN][MAXN];
int cnt[MAXN][MAXN][MAXN][MAXN];

int main() {
    int q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", board[i] + 1);
        for (int j = 1; j <= m; ++j) {
            sum[i][j] = (board[i][j] == '1') + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = i; k <= n; ++k) {
                for (int l = j; l <= m; ++l) {
                    cnt[i][j][k][l] = (sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1]) == 0;
                }
            }
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = i; k <= n; ++k) {
                for (int l = j; l <= m; ++l) {
                    cnt[i][j][k][l] += cnt[i + 1][j][k][l];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            for (int k = i; k <= n; ++k) {
                for (int l = j; l <= m; ++l) {
                    cnt[i][j][k][l] += cnt[i][j + 1][k][l];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = i; k <= n; ++k) {
                for (int l = j; l <= m; ++l) {
                    cnt[i][j][k][l] += cnt[i][j][k - 1][l];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = i; k <= n; ++k) {
                for (int l = j; l <= m; ++l) {
                    cnt[i][j][k][l] += cnt[i][j][k][l - 1];
                }
            }
        }
    }
    while (q--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", cnt[a][b][c][d]);
    }
    return 0;
}
