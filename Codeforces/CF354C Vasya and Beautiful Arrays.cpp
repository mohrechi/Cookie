#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXA = 2e6 + 5;

int cnt[MAXA];

int main() {
    int n, k, a;
    int minA = MAXA, maxA = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        minA = min(minA, a);
        maxA = max(maxA, a);
        ++cnt[a];
    }
    for (int i = 1; i < MAXA; ++i) {
        cnt[i] += cnt[i - 1];
    }
    int ans = 1;
    for (int i = minA; i >= 1; --i) {
        int num = 0;
        for (int j = i; j <= maxA; j += i) {
            num += cnt[j + min(k, i - 1)] - cnt[j - 1];
        }
        if (num == n) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
