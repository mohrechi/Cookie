#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10 + 5;
const int STEP_X[] = {0, 1, 0, -1};
const int STEP_Y[] = {1, 0, -1, 0};

int n, m;
char b[MAXN][MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", b[i] + 1);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (b[i][j] == 'W') {
                for (int k = 0; k < 4; ++k) {
                    int tx = i + STEP_X[k];
                    int ty = j + STEP_Y[k];
                    if (b[tx][ty] == 'P') {
                        ++cnt;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
