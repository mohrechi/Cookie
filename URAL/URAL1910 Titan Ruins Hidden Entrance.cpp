#include <bits/stdc++.h>

int main() {
    int n, a = 0, b = 0, c;
    scanf("%d", &n);
    int sum = 0, pos = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c);
        if (a + b + c > sum) {
            sum = a + b + c;
            pos = i;
        }
        a = b;
        b = c;
    }
    printf("%d %d\n", sum, pos);
    return 0;
}
