#include <bits/stdc++.h>

int main() {
    int n, k, a;
    int s1 = 0, s2 = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if (a >= k) {
            s1 += a - k;
        } else {
            s2 += k - a;
        }
    }
    printf("%d %d\n", s1, s2);
    return 0;
}
