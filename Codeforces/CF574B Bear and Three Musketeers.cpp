#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4000 + 5;

int n, m;
int a[MAXN], b[MAXN];
bool connect[MAXN][MAXN];
int degree[MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        ++degree[a[i]];
        ++degree[b[i]];
        connect[a[i]][b[i]] = connect[b[i]][a[i]] = true;
    }
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[j] != i && b[j] != i) {
                if (connect[i][a[j]] && connect[i][b[j]]) {
                    int d = degree[i] + degree[a[j]] + degree[b[j]] - 6;
                    if (ans == -1 || ans > d) {
                        ans = d;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
