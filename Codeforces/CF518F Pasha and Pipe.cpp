#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 10;

int n, m;
char board[MAXN][MAXN];

bool l[MAXN][MAXN], r[MAXN][MAXN], u[MAXN][MAXN], d[MAXN][MAXN];
int hu[MAXN][MAXN], hd[MAXN][MAXN], vl[MAXN][MAXN], vr[MAXN][MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", board[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            u[i][j] = board[i][j] != '#';
            if (i > 0) {
                u[i][j] &= u[i - 1][j];
            }
            l[i][j] = board[i][j] != '#';
            if (j > 0) {
                l[i][j] &= l[i][j - 1];
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            d[i][j] = board[i][j] != '#';
            if (i < n - 1) {
                d[i][j] &= d[i + 1][j];
            }
            r[i][j] = board[i][j] != '#';
            if (j < m - 1) {
                r[i][j] &= r[i][j + 1];
            }
        }
    }
    for (int i = 1; i < n - 1; ++i) {
        int start = -1, cntU = 0, cntD = 0;
        for (int j = 1; j < m; ++j) {
            if (j == m - 1 || board[i][j] == '#') {
                if (start != -1) {
                    for (int k = start; k < j; ++k) {
                        hu[i][k] = cntU;
                        hd[i][k] = cntD;
                    }
                    start = -1;
                    cntU = 0;
                    cntD = 0;
                }
            } else {
                if (start == -1) {
                    start = j;
                }
                cntU += u[i][j];
                cntD += d[i][j];
            }
        }
    }
    for (int j = 1; j < m - 1; ++j) {
        int start = -1, cntL = 0, cntR = 0;
        for (int i = 1; i < n; ++i) {
            if (i == n - 1 || board[i][j] == '#') {
                if (start != -1) {
                    for (int k = start; k < i; ++k) {
                        vl[k][j] = cntL;
                        vr[k][j] = cntR;
                    }
                    start = -1;
                    cntL = 0;
                    cntR = 0;
                }
            } else {
                if (start == -1) {
                    start = i;
                }
                cntL += l[i][j];
                cntR += r[i][j];
            }
        }
    }
    long long turn0 = 0;
    for (int i = 1; i < n - 1; ++i) {
        turn0 += r[i][0];
    }
    for (int j = 1; j < m - 1; ++j) {
        turn0 += d[0][j];
    }
    long long turn1 = 0;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            turn1 += l[i][j] && u[i][j];
            turn1 += u[i][j] && r[i][j];
            turn1 += r[i][j] && d[i][j];
            turn1 += d[i][j] && l[i][j];
        }
    }
    long long turn2 = 0;
    for (int i = 0; i < n; ++i) {
        u[i][0] = d[i][0] = l[i][0] = r[i][0] = 0;
        u[i][m - 1] = d[i][m - 1] = l[i][m - 1] = r[i][m - 1] = 0;
    }
    for (int j = 0; j < m; ++j) {
        u[0][j] = d[0][j] = l[0][j] = r[0][j] = 0;
        u[n - 1][j] = d[n - 1][j] = l[n - 1][j] = r[n - 1][j] = 0;
    }
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (u[i][j]) {
                if (hu[i][j]) {
                    turn2 += hu[i][j] - u[i][j] - u[i][j - 1] - u[i][j + 1];
                }
                if (hd[i][j]) {
                    turn2 += hd[i][j] - d[i][j];
                }
            }
            if (d[i][j]) {
                if (hd[i][j]) {
                    turn2 += hd[i][j] - d[i][j] - d[i][j - 1] - d[i][j + 1];
                }
                if (hu[i][j]) {
                    turn2 += hu[i][j] - u[i][j];
                }
            }
            if (l[i][j]) {
                if (vl[i][j]) {
                    turn2 += vl[i][j] - l[i][j] - l[i - 1][j] - l[i + 1][j];
                }
                if (vr[i][j]) {
                    turn2 += vr[i][j] - r[i][j];
                }
            }
            if (r[i][j]) {
                if (vr[i][j]) {
                    turn2 += vr[i][j] - r[i][j] - r[i - 1][j] - r[i + 1][j];
                }
                if (vl[i][j]) {
                    turn2 += vl[i][j] - l[i][j];
                }
            }
        }
    }
    turn2 >>= 1;
    cout << turn0 + turn1 + turn2 << endl;
    return 0;
}
