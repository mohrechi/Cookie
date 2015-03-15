#include <bits/stdc++.h>
const int MAXN = 100 + 5;
const int MAXM = MAXN * 2 + 5;

int n;
int board[MAXM][MAXM];

int main() {
    scanf("%d", &n);
    n = n * 2 + 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                board[i][j] = 0;
            } else {
                board[i][j] = ((i - 1) + j - 1 + n) % n + 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j > 1) {
                putchar(' ');
            }
            printf("%d", board[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
