#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, q;
int s[MAXN];

int main() {
    int a, l, r;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        s[i] = s[i - 1] + a % 2;
    }
    while (q--) {
        scanf("%d%d", &l, &r);
        if ((s[r] - s[l - 1]) % 2) {
            puts("Odd");
        } else {
            puts("Even");
        }
    }
    return 0;
}
