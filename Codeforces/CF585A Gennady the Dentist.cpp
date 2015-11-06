#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4005;

int n, v[MAXN], d[MAXN], p[MAXN];
bool leave[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &v[i], &d[i], &p[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (leave[i]) {
            continue;
        }
        ++cnt;
        for (int j = i + 1, reduce = 0; (v[i] || reduce) && j <= n; ++j) {
            if (leave[j]) {
                continue;
            }
            p[j] -= v[i] + reduce;
            if (v[i]) {
                --v[i];
            }
            if (p[j] < 0) {
                reduce += d[j];
                if (reduce > 1e7) {
                    reduce = 1e7;
                }
                leave[j] = true;
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; ++i) {
        if (!leave[i]) {
            printf("%d ", i);
        }
    }
    putchar('\n');
    return 0;
}
