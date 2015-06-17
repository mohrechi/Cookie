#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 2 + 10;

int n;
char s[MAXN];

int suffix[MAXN], srank[MAXN], prefix[MAXN];
int cnt[MAXN], rankA[MAXN], rankB[MAXN];

void initSuffix(const char* s, int n, int m) {
    int* x = rankA;
    for (int i = 0; i < n; ++i) x[i] = s[i];
    for (int i = 0; i < m; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) ++cnt[x[i]];
    for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) suffix[--cnt[x[i]]] = i;
    int* y = rankB;
    for (int k = 1; ; k <<= 1) {
        int j = 0;
        for (int i = n - k; i < n; ++i) y[j++] = i;
        for (int i = 0; i < n; ++i) if (suffix[i] >= k) y[j++] = suffix[i] - k;
        for (int i = 0; i < m; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) ++cnt[x[y[i]]];
        for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) suffix[--cnt[x[y[i]]]] = y[i];
        m = 1;
        swap(x, y);
        x[suffix[0]] = 0;
        for (int i = 1; i < n; ++i) {
            int a = suffix[i];
            int b = suffix[i - 1];
            int c = a + k >= n ? 0 : y[a + k];
            int d = b + k >= n ? 0 : y[b + k];
            a = y[a];
            b = y[b];
            x[suffix[i]] = (a == b && c == d) ? m - 1 : m++;
        }
        if (m >= n) break;
    }
}

void initPrefix(const char *s, int n) {
    int h = 0;
    for (int i = 0; i < n; ++i) srank[suffix[i]] = i;
    for (int i = 0; i < n; ++i) {
        if (srank[i] == 0) continue;
        int j = suffix[srank[i] - 1];
        if (h > 0) --h;;
        while (s[i + h] == s[j + h]) ++h;
        prefix[srank[i]] = h;
    }
}

int rlog[MAXN], mini[20][MAXN];

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
        mini[0][i] = prefix[i];
    }
    for (int i = 1; i <= rlog[n]; ++i) {
        int m = n - (1 << i) + 1;
        for (int j = 1; j <= m; ++j) {
            mini[i][j] = min(mini[i - 1][j], mini[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int queryRMQ(int l, int r) {
    if (l > r) {
        swap(l, r);
    }
    ++l;
    int t = rlog[r - l + 1];
    return min(mini[t][l], mini[t][r - (1 << t) + 1]);
}

int main() {
    initLog();
    gets(s);
    n = strlen(s);
    s[n] = '$';
    for (int i = n + n, j = 0; i > n; --i, ++j) {
        s[i] = s[j];
    }
    initSuffix(s, n + n + 1, 128);
    initPrefix(s, n + n + 1);
    initRMQ(n + n);
    int len = 1, pos = 0;
    for (int i = 0; i < n; ++i) {
        int t = queryRMQ(srank[i], srank[n + n - i]);
        if (t * 2 - 1 > len) {
            len = t * 2 - 1;
            pos = i - t + 1;
        }
        t = queryRMQ(srank[i], srank[n + n - i + 1]);
        if (t * 2 > len) {
            len = t * 2;
            pos = i - t;
        }
    }
    for (int i = 0; i < len; ++i) {
        putchar(s[pos + i]);
    }
    putchar('\n');
    return 0;
}
