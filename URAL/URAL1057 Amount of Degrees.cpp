#include <bits/stdc++.h>
using namespace std;

int c[32][32];

int solve(int x, int k, int b) {
    int bits[32], bitNum = 0;
    while (x) {
        bits[bitNum++] = x % b;
        x /= b;
    }
    int sum = 0, cnt = 0;
    for (int i = bitNum - 1; i >= 0; --i) {
        if (bits[i] > 1) {
            sum += c[i + 1][k - cnt];
            break;
        }
        if (bits[i] == 1) {
            if (i >= k - cnt) {
                sum += c[i][k - cnt];
            }
            if (++cnt > k) {
                break;
            }
        }
        if (i == 0 && cnt == k) {
            ++sum;
        }
    }
    return sum;
}

int main() {
    int x, y, k, b;
    for (int i = 0; i < 32; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    while (scanf("%d%d%d%d", &x, &y, &k, &b) != EOF) {
        printf("%d\n", solve(y, k, b) - solve(x - 1, k, b));
    }
    return 0;
}
