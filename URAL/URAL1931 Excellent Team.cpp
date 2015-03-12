#include <bits/stdc++.h>

int main() {
    int n, a, b;
    int num = 0, maxNum = 0, oriPos = 1, pos = 1;
    scanf("%d%d", &n, &a);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &b);
        if (++num > maxNum) {
            maxNum = num;
            pos = oriPos;
        }
        if (a > b) {
            a = b;
            num = 1;
            oriPos = i;
        }
    }
    printf("%d\n", pos);
    return 0;
}
