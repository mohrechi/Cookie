#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 10;

double c[MAXN][MAXN];
double dp[MAXN][MAXN];

double getC(int n, int m) {
    if (c[n][m] > -0.5) {
        return c[n][m];
    }
    if (n == 0 || m == 0 || n == m) {
        return c[n][m] = 1;
    }
    return c[n][m] = getC(n - 1, m) + getC(n - 1, m - 1);
}

double getDp(int x, int y) {
    if (dp[x][y] > -0.5) {
        return dp[x][y];
    }
    if (x <= y) {
        return dp[x][y] = 0.0;
    }
    if (y == 0) {
        return dp[x][y] = x;
    }
    x -= y;
    double maxExpect = 0.0;
    for (int i = 0; i <= x + y; ++i) {
        double expect = 0.0;
        for (int j = 0; j <= min(i, y); ++j) {
            expect += getDp(x - (i - j), y - j) * getC(x, i - j) * getC(y, j) / getC(x + y, i);
        }
        maxExpect = max(maxExpect, expect);
    }
    return dp[x + y][y] = maxExpect;
}

int main() {
    int n, k;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            c[i][j] = dp[i][j] = -1.0;
        }
    }
    while (cin >> n >> k) {
        printf("%.8f\n", getDp(n - k, k));
    }
    return 0;
}
