#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;

int main() {
    int n, a[MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 0, cnt = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum > 710) {
            break;
        }
        ++cnt;
        if (sum > 350) {
            ans += (sum - 350);
        }
    }
    printf("%d %d\n", cnt, ans);
    return 0;
}
