#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n, h[MAXN];
int l[MAXN], r[MAXN];

void calc(int init, int inc, int rec[MAXN]) {
    stack<int> stk;
    stk.push(init - inc);
    for (int i = init; 1 <= i && i <= n; i += inc) {
        while (h[i] <= h[stk.top()]) {
            stk.pop();
        }
        rec[i] = stk.top();
        stk.push(i);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }
    calc(1, +1, l);
    calc(n, -1, r);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, (long long)h[i] * (r[i] - l[i] - 1));
    }
    cout << ans << endl;
    return 0;
}
