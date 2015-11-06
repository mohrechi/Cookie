#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e6 + 5;

int n, b[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0, w; i < n; ++i) {
        scanf("%d", &w);
        ++b[w];
    }
    int cnt = 0;
    for (int i = 0; i < MAXN - 1; ++i) {
        cnt += b[i] & 1;
        b[i + 1] += b[i] >> 1;
    }
    printf("%d\n", cnt);
    return 0;
}
