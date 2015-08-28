#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

int n, w;
int a[MAXN], b[MAXN];
int fail[MAXN];

inline void readArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
}

inline void diffArray(int a[], int& n) {
    --n;
    for (int i = n; i > 0; --i) {
        a[i] -= a[i - 1];
    }
}

int main() {
    scanf("%d%d", &n, &w);
    readArray(a, n);
    readArray(b, w);
    if (w == 1) {
        printf("%d\n", n);
        return 0;
    }
    diffArray(a, n);
    diffArray(b, w);
    fail[1] = 0;
    for (int i = 2, j = 0; i <= w; ++i) {
        while (j != 0 && b[j + 1] != b[i]) {
            j = fail[j];
        }
        if (b[j + 1] == b[i]) {
            ++j;
        }
        fail[i] = j;
    }
    int ans = 0;
    for (int i = 1, j = 0; i <= n; ++i) {
        while (j != 0 && b[j + 1] != a[i]) {
            j = fail[j];
        }
        if (b[j + 1] == a[i]) {
            if (++j == w) {
                ++ans;
                j = fail[j];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
