#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n, h[MAXN];
int a[MAXN], b[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }
    int idx = 1;
    a[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (h[idx] + i - idx < h[i]) {
            a[i] = h[idx] + i - idx;
        } else {
            a[i] = h[i];
            idx = i;
        }
        a[i] = min(a[i], i);
    }
    idx = n;
    b[n] = 1;
    for (int i = n - 1; i >= 1; --i) {
        if (h[idx] + idx - i < h[i]) {
            b[i] = h[idx] + idx - i;
        } else {
            b[i] = h[i];
            idx = i;
        }
        b[i] = min(b[i], n - i + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, min(a[i], b[i]));
    }
    printf("%d\n", ans);
    return 0;
}
