#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

int n;
char s[MAXN];

int suf[MAXN], rnk[MAXN], pre[MAXN];
int cnt[MAXN], rnkA[MAXN], rnkB[MAXN];

void initSuf(const char* s, int n, int m) {
    int* x = rnkA;
    for (int i = 0; i < n; ++i) x[i] = s[i];
    for (int i = 0; i < m; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) ++cnt[x[i]];
    for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) suf[--cnt[x[i]]] = i;
    int* y = rnkB;
    for (int k = 1; ; k <<= 1) {
        int j = 0;
        for (int i = n - k; i < n; ++i) y[j++] = i;
        for (int i = 0; i < n; ++i) if (suf[i] >= k) y[j++] = suf[i] - k;
        for (int i = 0; i < m; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) ++cnt[x[y[i]]];
        for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) suf[--cnt[x[y[i]]]] = y[i];
        swap(x, y);
        m = 1;
        x[suf[0]] = 0;
        for (int i = 1; i < n; ++i) {
            int a = suf[i];
            int b = suf[i - 1];
            int c = a + k >= n ? -1 : y[a + k];
            int d = b + k >= n ? -1 : y[b + k];
            a = y[a];
            b = y[b];
            x[suf[i]] = (a == b && c == d) ? m - 1 : m++;
        }
        if (m >= n) break;
    }
}

void initPre(const char* s, int n) {
    int h = 0;
    for (int i = 0; i < n; ++i) rnk[suf[i]] = i;
    for (int i = 0; i < n; ++i) {
        if (rnk[i] == 0) continue;
        int j = suf[rnk[i] - 1];
        if (h > 0) --h;
        while (s[i + h] == s[j + h]) ++h;
        pre[rnk[i]] = h;
    }
    pre[n] = 0;
}

int rlog[MAXN], rmin[20][MAXN];

void initLog() {
    rlog[0] = -1;
    for (int i = 1; i < MAXN; ++i) {
        rlog[i] = rlog[i - 1];
        if ((i & (i - 1)) == 0) {
            ++rlog[i];
        }
    }
}

void initRMQ(int n) {
    for (int i = 1; i <= n; ++i) {
        rmin[0][i] = pre[i];
    }
    for (int i = 1; i <= rlog[n]; ++i) {
        int m = n - (1 << i) + 1;
        for (int j = 1; j <= m; ++j) {
            rmin[i][j] = min(rmin[i - 1][j], rmin[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int queryRMQ(int a, int b) {
    a = rnk[a];
    b = rnk[b];
    if (a > b) {
        swap(a, b);
    }
    ++a;
    int t = rlog[b - a + 1];
    return min(rmin[t][a], rmin[t][b - (1 << t) + 1]);
}

int main() {
    int t = 0;
    initLog();
    while (gets(s), s[0] != '#') {
        for (n = 0; s[n]; ++n);
        initSuf(s, n, 128);
        initPre(s, n);
        initRMQ(n);
        int rep = 1;
        set<int> candidates;
        candidates.insert(1);
        for (int l = 1; l < n; ++l) {
            for (int i = 0; i + l < n; i += l) {
                int t = queryRMQ(i, i + l);
                int k = t / l + 1;
                int f = i;
                if (t % l && f >= l - t % l) {
                    f -= l - t % l;
                    if (queryRMQ(f, f + l) >= max(l, t)) {
                        ++k;
                    } else {
                        f = i;
                    }
                }
                if (k > rep) {
                    rep = k;
                    candidates.clear();
                    candidates.insert(l);
                } else if (k == rep) {
                    candidates.insert(l);
                }
            }
        }
        int pos, len = 0;
        for (int i = 0; i < n && len == 0; ++i) {
            for (set<int>::iterator it = candidates.begin(); it != candidates.end(); ++it) {
                int l = *it;
                if (rep > 1 && suf[i] + l >= n) {
                    continue;
                }
                if (queryRMQ(suf[i], suf[i] + l) >= (rep - 1) * l) {
                    pos = suf[i];
                    len = l * rep;
                    break;
                }
            }
        }
        printf("Case %d: ", ++t);
        for (int i = 0; i < len; ++i) {
            putchar(s[pos + i]);
        }
        putchar('\n');
    }
    return 0;
}
