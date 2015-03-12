#include <bits/stdc++.h>
using namespace std;

int n, k, c[105][105];
bool visit[105];
int near[105];

int main() {
    int a;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &a);
        visit[a] = true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &c[i][j]);
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (c[i][j] > c[i][k] + c[k][j]) {
                    c[i][j] = c[i][k] + c[k][j];
                }
            }
        }
    }
    memset(near, 0x3f, sizeof(near));
    for (int i = 1; i <= n; ++i) {
        if (visit[i]) {
            for (int j = 1; j <= n; ++j) {
                near[j] = min(near[j], c[i][j]);
            }
        }
    }
    int sum = 0;
    while (k++ < n) {
        int inf = 0x7fffffff;
        int pos = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visit[i]) {
                if (near[i] < inf) {
                    inf = near[i];
                    pos = i;
                }
            }
        }
        visit[pos] = true;
        sum += near[pos];
        for (int i = 1; i <= n; ++i) {
            near[i] = min(near[i], c[i][pos]);
        }
    }
    cout << sum << endl;
    return 0;
}
