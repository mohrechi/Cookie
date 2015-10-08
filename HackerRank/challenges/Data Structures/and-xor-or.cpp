#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

int n, a[MAXN];

int search() {
    int ans = 0;
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && stk.top() >= a[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            ans = max(ans, stk.top() ^ a[i]);
        }
        stk.push(a[i]);
    }
    return ans;
}

int main() {
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (i) {
            ans = max(ans, a[i] ^ a[i - 1]);
        }
    }
    ans = max(ans, search());
    reverse(a, a + n);
    ans = max(ans, search());
    printf("%d\n", ans);
    return 0;
}
