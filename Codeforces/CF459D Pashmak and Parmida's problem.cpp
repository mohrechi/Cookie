#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int n, a[MAXN];
int foreward[MAXN], backward[MAXN];
int bit[MAXN];

inline int lowbit(int x) {
    return x & (-x);
}

void update(int x) {
    while (x <= n) {
        ++bit[x];
        x += lowbit(x);
    }
}

int query(int x) {
    int ret = 0;
    while (x) {
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

int main() {
    map<int, int> cnt;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        foreward[i] = ++cnt[a[i]];
    }
    cnt.clear();
    for (int j = n; j >= 1; --j) {
        backward[j] = ++cnt[a[j]];
    }
    long long ans = 0;
    for (int i = n; i >= 1; --i) {
        ans += query(foreward[i] - 1);
        update(backward[i]);
    }
    cout << ans << endl;
    return 0;
}
