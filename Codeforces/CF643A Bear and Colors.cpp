#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 5;

int n, t[MAXN];
int ans[MAXN], cnt[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < n; ++i) {
        int maxCnt = 0, color = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j < n; ++j) {
            ++cnt[t[j]];
            if (cnt[t[j]] > maxCnt || (cnt[t[j]] == maxCnt && t[j] < color)) {
                color = t[j];
                maxCnt = cnt[t[j]];
            }
            ++ans[color];
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
