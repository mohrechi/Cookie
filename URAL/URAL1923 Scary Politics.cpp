#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;
const int DIR_X[] = {0, 1, 0, -1};
const int DIR_Y[] = {1, 0, -1, 0};

int n, m;
char terror[MAXN][MAXN];
bool brazico[MAXN][MAXN];
bool mexil[MAXN][MAXN];
bool visit[MAXN][MAXN];

void dfs(bool country[MAXN][MAXN], bool other[MAXN][MAXN], int x, int y, char alley) {
    visit[x][y] = true;
    country[x][y] = true;
    for (int k = 0; k < 4; ++k) {
        int tx = x + DIR_X[k];
        int ty = y + DIR_Y[k];
        if (0 <= tx && tx < n) {
            if (0 <= ty && ty < m) {
                if (!visit[tx][ty] && !other[tx][ty]) {
                    if (country[tx][ty] || terror[tx][ty] == alley) {
                        dfs(country, other, tx, ty, alley);
                    }
                }
            }
        }
    }
}

int count(bool country[MAXN][MAXN]) {
    int num = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            num += country[i][j];
        }
    }
    return num;
}

int main() {
    int l, a;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", terror[i]);
    }
    dfs(brazico, mexil, n - 1, 0, terror[n - 1][0]);
    memset(visit, false, sizeof(visit));
    dfs(mexil, brazico, 0, m - 1, terror[0][m - 1]);
    scanf("%d", &l);
    for (int i = 0; i < l; ++i) {
        scanf("%d", &a);
        memset(visit, false, sizeof(visit));
        if (i & 1) {
            dfs(mexil, brazico, 0, m - 1, a + '0');
        } else {
            dfs(brazico, mexil, n - 1, 0, a + '0');
        }
    }
    printf("%d\n", count(brazico));
    printf("%d\n", count(mexil));
    return 0;
}
