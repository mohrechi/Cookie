#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n;
pair<int, int> a[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a, a + n);
    int ans = 0, maxVal = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].second < maxVal) {
            ++ans;
        } else {
            maxVal = a[i].second;
        }
    }
    printf("%d\n", ans);
    return 0;
}
