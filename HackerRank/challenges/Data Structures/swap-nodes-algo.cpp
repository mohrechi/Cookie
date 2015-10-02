#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1025;

int n, l[MAXN], r[MAXN];

void print(int u, int d, int k) {
    if (u == -1) {
        return;
    }
    if (d % k == 0) {
        swap(l[u], r[u]);
    }
    print(l[u], d + 1, k);
    printf("%d ", u);
    print(r[u], d + 1, k);
}

int main() {
    int t;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
    }
    scanf("%d", &t);
    while (t--) {
        int k;
        scanf("%d", &k);
        print(1, 1, k);
        putchar('\n');
    }
    return 0;
}
