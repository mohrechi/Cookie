#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, q;
int a[MAXN], num[MAXN][3];

int main() {
    int l, r;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        for (int j = 0; j < 3; ++j) {
            num[i][j] = num[i - 1][j] + (a[i] % 3 == j);
        }
    }
    while (q--) {
        scanf("%d%d", &l, &r);
        --l;
        int num0 = num[r][0] - num[l][0];
        if (num0 == 1) {
            puts("0");
        } else {
            int num2 = num[r][2] - num[l][2];
            if (num2 & 1) {
                puts("2");
            } else {
                puts("1");
            }
        }
    }
    return 0;
}
