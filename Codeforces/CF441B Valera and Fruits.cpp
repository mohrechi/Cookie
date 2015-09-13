#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 5;

int n, v;
int cnt[MAXN];

int main() {
    int a, b;
    scanf("%d%d", &n, &v);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        cnt[a] += b;
    }
    int ans = 0, last = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (last >= v) {
            ans += v;
            last = cnt[i];
        } else {
            ans += last;
            int rem = v - last;
            if (cnt[i] >= rem) {
                ans += rem;
                last = cnt[i] - rem;
            } else {
                ans += cnt[i];
                last = 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
