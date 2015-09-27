#include <bits/stdc++.h>
using namespace std;
const int MAXN = 800 + 5;

int n, m;
struct Pair {
    int x, y, w;
    bool operator <(const Pair &p) const {
        return w > p.w;
    }
} pairs[MAXN * MAXN];
int match[MAXN];

int main() {
    int w;
    scanf("%d", &n);
    n <<= 1;
    for (int x = 2; x <= n; ++x) {
        for (int y = 1; y < x; ++y) {
            scanf("%d", &w);
            pairs[m++] = {x, y, w};
        }
    }
    sort(pairs, pairs + m);
    for (int i = 0; i < m; ++i) {
        int& x = pairs[i].x;
        int& y = pairs[i].y;
        if (match[x] == 0 && match[y] == 0) {
            match[x] = y;
            match[y] = x;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", match[i]);
    }
    putchar('\n');
    return 0;
}
