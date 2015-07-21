#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int n, a[MAXN];
int lpos[MAXN];
int stk[MAXN], top;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i >= 1; --i) {
        while (top > 0 and a[i] > a[stk[top - 1]]) {
            lpos[stk[top - 1]] = i + 1;
            --top;
        }
        stk[top++] = i;
    }
    while (top > 0) {
        lpos[stk[--top]] = 1;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (top > 0 and a[i] < a[stk[top - 1]]) {
            --top;
        }
        stk[top++] = i;
        int l = 0, r = top - 1;
        int m = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (stk[mid] >= lpos[i]) {
                r = mid - 1;
                m = min(m, mid);
            } else {
                l = mid + 1;
            }
        }
        ans += top - m;
    }
    cout << ans << endl;
    return 0;
}
