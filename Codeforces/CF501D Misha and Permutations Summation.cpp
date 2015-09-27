#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;

int n, p[MAXN], q[MAXN];

int bits[MAXN];

inline int lowbit(int x) {
    return x & (-x);
}

void update(int x) {
    while (x <= n) {
        ++bits[x];
        x += lowbit(x);
    }
}

int query(int x) {
    int ret = 0;
    while (x > 0) {
        ret += bits[x];
        x -= lowbit(x);
    }
    return ret;
}

int fp[MAXN], fq[MAXN];

void getFactor(int p[], int fp[]) {
    for (int i = 1; i <= n; ++i) {
        fp[n - i] = p[i] - query(p[i]);
        update(p[i] + 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    getFactor(p, fp);
    for (int j = 1; j <= n; ++j) {
        scanf("%d", &q[j]);
    }
    memset(bits, 0, sizeof(bits));
    getFactor(q, fq);
    int carry = 0;
    for (int i = 0; i < n; ++i) {
        fp[i] += fq[i] + carry;
        carry = fp[i] / (i + 1);
        fp[i] %= i + 1;
    }
    memset(bits, 0, sizeof(bits));
    for (int i = 1; i <= n; ++i) {
        int num = fp[n - i];
        int l = 1, r = n;
        p[i] = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid - query(mid) >= num + 1) {
                r = mid - 1;
                p[i] = min(p[i], mid);
            } else {
                l = mid + 1;
            }
        }
        update(p[i]);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", p[i] - 1);
    }
    putchar('\n');
    return 0;
}
