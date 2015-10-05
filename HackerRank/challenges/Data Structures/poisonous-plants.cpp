#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 5;

int n, p[MAXN], t[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    stack<int> stk;
    int ans = 0;
    for (int i = n; i >= 1; --i) {
        while (!stk.empty() && p[i] < p[stk.top()]) {
            stk.pop();
            t[i] = max(t[i] + 1, t[stk.top()]);
        }
        stk.push(i);
        ans = max(ans, t[i]);
    }
    printf("%d\n", ans);
    return 0;
}
