#include <bits/stdc++.h>

int main() {
    int n;
    scanf("%d", &n);
    if (((n + 1) >> 1) & 1) {
        puts("grimy");
    } else {
        puts("black");
    }
    return 0;
}
