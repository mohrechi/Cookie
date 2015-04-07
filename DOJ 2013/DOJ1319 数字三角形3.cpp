#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;

long long tri[MAXN][MAXN];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                scanf("%lld", &tri[i][j]);
                if (i == (n >> 1)) {
                    if (j != (n >> 1)) {
                        tri[i][j] = -0x3f3f3f3f3f3f3f3fLL;
                    }
                }
                tri[i][j] += max(tri[i - 1][j], tri[i - 1][j - 1]);
            }
        }
        for (int i = 2; i <= n; ++i) {
            tri[n][i] = max(tri[n][i], tri[n][i - 1]);
        }
        printf("%lld\n", tri[n][n]);
    }
    return 0;
}
