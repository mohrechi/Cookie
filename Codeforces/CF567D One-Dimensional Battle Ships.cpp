#include <bits/stdc++.h>
using namespace std;

inline int getNum(int n, int a) {
    if (n < a) {
        return 0;
    }
    return 1 + (n - a) / (a + 1);
}

int main() {
    int n, m, k, a, x;
    while (scanf("%d%d%d", &n, &k, &a) != EOF) {
        scanf("%d", &m);
        int ans = -1;
        set<int> xs;
        xs.insert(0);
        xs.insert(n + 1);
        int num = getNum(n, a);
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &x);
            if (ans == -1) {
                auto it = xs.upper_bound(x);
                int r = *it;
                int l = *(--it);
                num -= getNum(r - l - 1, a);
                num += getNum(x - l - 1, a);
                num += getNum(r - x - 1, a);
                xs.insert(x);
                if (num < k) {
                    ans = i;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
