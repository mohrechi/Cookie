#include <bits/stdc++.h>
using namespace std;
const int MAXN = 250 + 10;

int n, x[MAXN], y[MAXN];
char board[MAXN][MAXN];

int main() {
    int minX = 0, maxX = -0;
    int minY = 0, maxY = -0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        minX = min(minX, x[i]);
        maxX = max(maxX, x[i]);
        minY = min(minY, y[i]);
        maxY = max(maxY, y[i]);
    }
    int lenX = maxX - minX + 1;
    int lenY = maxY - minY + 1;
    for (int i = 0; i < lenY; ++i) {
        for (int j = 0; j < lenX; ++j) {
            board[i][j] = '.';
        }
    }
    for (int i = 0; i < lenY; ++i) {
        board[i][-minX] = '|';
    }
    for (int i = 0; i < lenX; ++i) {
        board[lenY+minY-1][i] = '-';
    }
    board[lenY+minY-1][-minX] = '+';
    for (int i = 0; i < n; ++i) {
        board[maxY - y[i]][x[i] - minX] = '*';
    }
    for (int i = 0; i < lenY; ++i) {
        puts(board[i]);
    }
    return 0;
}
