#include <bits/stdc++.h>

int main() {
    int n, m;
    while (~scanf("%d", &n)) {
        m = n;
        while (n >= 5) {
            m += n / 5;
            n = n / 5 + n % 5;
        }
        printf("%d\n", m);
    }
    return 0;
}
