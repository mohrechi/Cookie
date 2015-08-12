#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int n, m, dx, dy;
int posY[MAXN], cnt[MAXN];

int main() {
    int x, y;
    scanf("%d%d%d%d", &n, &m, &dx, &dy);
    x = 0, y = 0;
    do {
        posY[x] = y;
        x = (x + dx) % n;
        y = (y + dy) % n;
    } while (x != 0 || y != 0);
    while (m--) {
        scanf("%d%d", &x, &y);
        if (y >= posY[x]) {
            ++cnt[y - posY[x]];
        } else {
            ++cnt[y + n - posY[x]];
        }
    }
    int shift = 0;
    for (int i = 1; i < n; ++i) {
        if (cnt[i] > cnt[shift]) {
            shift = i;
        }
    }
    printf("0 %d\n", shift);
    return 0;
}
