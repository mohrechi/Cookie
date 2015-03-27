#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;

int tri[MAXN][MAXN];
bool mod[MAXN][MAXN][100];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        memset(mod, false, sizeof(mod));
        mod[0][0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                scanf("%d", &tri[i][j]);
                for (int k = 0; k < 100; ++k) {
                    if (mod[i - 1][j][k] || mod[i - 1][j - 1][k]) {
                        mod[i][j][(k + tri[i][j]) % 100] = true;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int k = 99; k > ans; --k) {
                if (mod[n][i][k]) {
                    ans = k;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
