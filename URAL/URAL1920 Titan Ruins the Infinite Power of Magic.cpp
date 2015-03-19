#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    while (~scanf("%d%d", &n, &l)) {
        if ((l & 1) || n * n < l) {
            puts("Unsuitable device");
            continue;
        }
        puts("Overwhelming power of magic");
        if (n * 2 >= l) {
            n = l >> 1;
            for (int i = 1; i <= n; ++i) {
                printf("%d %d\n", i, 1);
            }
            for (int i = n; i >= 1; --i) {
                printf("%d %d\n", i, 2);
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                printf("%d %d\n", i, 1);
            }
            int x = n, y = 2, len = n;
            bool right = true, up = true;
            while (true) {
                ++len;
                printf("%d %d\n", x, y);
                if (x - 1 + y - 2 == l - len) {
                    if (right) {
                        while (x > 1) {
                            printf("%d %d\n", --x, y);
                        }
                        while (y > 2) {
                            printf("%d %d\n", x, --y);
                        }
                    } else {
                        while (y > 2) {
                            printf("%d %d\n", x, --y);
                        }
                        while (x > 1) {
                            printf("%d %d\n", --x, y);
                        }
                    }
                    break;
                }
                if ((n & 1) && x <= 2) {
                    if (up) {
                        if (x == 1) {
                            --y;
                            up = false;
                        } else {
                            --x;
                        }
                    } else {
                        if (x == 2) {
                            --y;
                            up = true;
                        } else {
                            ++x;
                        }
                    }
                } else {
                    if (right) {
                        if (y == n) {
                            --x;
                            right = false;
                        } else {
                            ++y;
                        }
                    } else {
                        if (y == 2) {
                            --x;
                            right = true;
                        } else {
                            --y;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
