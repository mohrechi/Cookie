#include <bits/stdc++.h>

int main() {
    int n, k, b, g;
    scanf("%d%d", &n, &k);
    int s = k - 2;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &b, &g);
        s += b - 2 - g;
    }
    if (s < 0) {
        puts("Big Bang!");
    } else {
        printf("%d\n", s);
    }
    return 0;
}
