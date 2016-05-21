#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 10;

inline long long num(long long x) {
    return (x + 1) * x / 2;
}

inline long long num(long long x, long long y) {
    return num(x) * num(y);
}

int main() {
    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int ans = 0, near = MAXN;
        for (int x = 1, y = 1; x <= 2000; ++x) {
            int l = 1, r = 2000;
            y = 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (num(x, mid) <= N) {
                    l = mid + 1;
                    y = max(y, mid);
                } else {
                    r = mid - 1;
                }
            }
            int t1 = abs(num(x, y) - N);
            int t2 = abs(num(x, y + 1) - N);
            int t = min(t1, t2);
            if (t2 < t1) {
                ++y;
            }
            if (t < near) {
                near = t;
                ans = x * y;
            } else if (t == near) {
                ans = max(ans, x * y);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
