#include <bits/stdc++.h>
using namespace std;

int num[1000][1000];

int readNum() {
    bool negative = false;
    char buffer[20];
    scanf("%s", buffer);
    if (buffer[0] == '-') {
        negative = true;
    }
    int num = 0;
    for (int i = 0; buffer[i]; ++i) {
        if (buffer[i] == '.') {
            ++i;
            for (int j = 0; j < 3; ++j) {
                if (buffer[i]) {
                    num = num * 10 + buffer[i++] - '0';
                } else {
                    num *= 10;
                }
            }
            break;
        }
    }
    return negative ? (1000 - num) % 1000 : num;
}

int main() {
    int n, x, y;
    scanf("%d", &n);
    while (n--) {
        x = readNum();
        y = readNum();
        ++num[x][y];
    }
    int maxNum = 0, mx, my;
    int minDist = 0x7fffffff;
    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j < 1000; ++j) {
            if (num[i][j] >= maxNum) {
                int distX = i > 500 ? (1000 - i) : i;
                int distY = j > 500 ? (1000 - j) : j;
                int dist = distX * distX + distY * distY;
                if (num[i][j] > maxNum) {
                    maxNum = num[i][j];
                    minDist = dist;
                } else if (num[i][j] == maxNum) {
                    if (dist < minDist) {
                        minDist = dist;
                    }
                }
            }
        }
    }
    printf("%d %.8f\n", maxNum, sqrt(minDist) / 1e3);
    return 0;
}
