#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 5;
const int MAXC = 2e9 + 5;

int n, k;
int a[MAXN], b[MAXN];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    int ans = 0;
    long long l = 0, r = MAXC;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        long long rem = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] * mid > b[i]) {
                rem += a[i] * mid - b[i];
                if (rem > k) {
                    break;
                }
            }
        }
        if (rem > k) {
            r = mid - 1;
        } else {
            l = mid + 1;
            ans = max(ans, (int)mid);
        }
    }
    printf("%d\n", ans);
    return 0;
}
