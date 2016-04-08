#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 5;

int n, q;
int a[MAXN];
int stk[MAXN], top;

int main() {
    int l, r;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i > 1) {
            a[i - 1] = abs(a[i] - a[i - 1]);
        }
    }
    #ifdef LOCAL_DEBUG
    for (int i = 1; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    #endif // LOCAL_DEBUG
    while (q--) {
        cin >> l >> r;
        if (l == r) {
            cout << 0 << endl;
            continue;
        }
        long long temp = 0, sum = 0;
        stk[0] = l - 1;
        top = 1;
        for (int i = l; i < r; ++i) {
            while (top > 1 && a[i] >= a[stk[top - 1]]) {
                --top;
                temp += 1LL * (stk[top] - stk[top - 1]) * (a[i] - a[stk[top]]);
            }
            stk[top++] = i;
            temp += a[i];
            sum += temp;
        }
        cout << sum << endl;
    }
    return 0;
}
