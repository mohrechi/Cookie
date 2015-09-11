#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXM = (1 << 20) + 5;

long long dp[MAXM];

struct Friend {
    int x, k, p;
    void input() {
        int m, s;
        scanf("%d%d%d", &x, &k, &m);
        p = 0;
        while (m--) {
            scanf("%d", &s);
            p |= 1 << (s - 1);
        }
    }
    bool operator <(const Friend &fri) const {
        return k < fri.k;
    }
} fri[MAXN];

inline void setVal(long long &x, long long val) {
    if (x == -1 || x > val) {
        x = val;
    }
}

int main() {
    int n, m, b;
    scanf("%d%d%d", &n, &m, &b);
    for (int i = 0; i < n; ++i) {
        fri[i].input();
    }
    sort(fri, fri + n);
    long long ans = -1;
    int maxState = (1 << m) - 1;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = maxState; j >= 0; --j) {
            if (dp[j] != -1) {
                setVal(dp[j | fri[i].p], dp[j] + fri[i].x);
            }
        }
        if (dp[maxState] != -1) {
            setVal(ans, dp[maxState] + (long long)fri[i].k * b);
        }
    }
    cout << ans << endl;
    return 0;
}
