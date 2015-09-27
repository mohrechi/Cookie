#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int a[MAXN], b[MAXN];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    map<int, int> cnt;
    for (int i = 1; i <= m; ++i) {
        int maxIdx = 1;
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[j]);
            if (a[j] > a[maxIdx]) {
                maxIdx = j;
            }
        }
        ++cnt[maxIdx];
        b[i] = maxIdx;
    }
    int maxIdx = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > cnt[maxIdx]) {
            maxIdx = i;
        }
    }
    printf("%d\n", maxIdx);
    return 0;
}
