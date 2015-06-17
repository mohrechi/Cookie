#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 * 2 + 10;

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
            x[suf[i]] = (a == b and c == d) ? m - 1 : m++;
        }
        if (m >= n) break;
    }
}

void initPre(const char* s, int n) {
    int h = 0;
    for (int i = 0; i < n; ++i) rnk[suf[i]] = i;
    for (int i = 0; i < n; ++i) {
        if (rnk[i] == 0) continue;
        if (h > 0) --h;
        int j = suf[rnk[i] - 1];
        while (s[i + h] == s[j + h]) ++h;
        pre[rnk[i]] = h;
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    s[n] = '$';
    scanf("%s", s + n + 1);
    initSuf(s, n + n + 1, 128);
    initPre(s, n + n + 1);
    int len = 0, pos;
    for (int i = 1; i < n + n + 1; ++i) {
        if ((suf[i] < n) ^ (suf[i - 1] < n)) {
            if (pre[i] > len) {
                len = pre[i];
                pos = suf[i];
            }
        }
    }
    s[pos + len] = 0;
    puts(s + pos);
    return 0;
}
