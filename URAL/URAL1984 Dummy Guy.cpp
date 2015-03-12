#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        puts("1");
    } else if (n == 2) {
        puts("2");
    } else {
        printf("%.8f\n", 1.0 / sin(acos(-1.0) / n) + 1.0);
    }
    return 0;
}
