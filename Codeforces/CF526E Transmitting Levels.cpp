#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int n, q;
long long a[MAXN], b;
long long sum[MAXN * 2];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        sum[n + i] = sum[n + i - 1] + a[i];
    }
    while (q--) {
        scanf("%lld", &b);
        if (sum[n] <= b) {
            puts("1");
            continue;
        }
        int minLen = n;
        int start = 0, end = 0;
        for (int i = 1, j = 1; i <= (n << 1);) {
            while (i <= (n << 1) && sum[i] - sum[j - 1] <= b) {
                ++i;
            }
            int len = i - j;
            if (len < minLen) {
                minLen = len;
                start = j;
                end = i;
            }
            while (sum[i] - sum[j - 1] > b) {
                ++j;
            }
        }
        int minGroup = n;
        for (int k = start; k <= end; ++k) {
            start = (k - 1) % n + 1;
            int group = 0;
            for (int i = start; i < n + start;) {
                ++group;
                if (i + minLen > n + start) {
                    break;
                }
                for (int j = i + minLen - 1; j <= n + start; ++j) {
                    if (j == n + start || sum[j] - sum[i - 1] > b) {
                        i = j;
                        break;
                    }
                }
            }
            minGroup = min(minGroup, group);
        }
        printf("%d\n", minGroup);
    }
    return 0;
}
