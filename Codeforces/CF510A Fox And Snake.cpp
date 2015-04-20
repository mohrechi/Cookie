#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i & 1) {
                    if ((i >> 1) & 1) {
                        if (j > 0) {
                            putchar('.');
                        } else {
                            putchar('#');
                        }
                    } else {
                        if (j < m - 1) {
                            putchar('.');
                        } else {
                            putchar('#');
                        }
                    }
                } else {
                    putchar('#');
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
