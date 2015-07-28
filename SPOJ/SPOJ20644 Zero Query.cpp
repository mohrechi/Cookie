#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50000 + 10;
const int SHIFT = 50000;

int n, m;
int s[MAXN];
int block[MAXN];
struct Query {
    int idx, l, r;
    bool operator <(const Query &query) const {
        if (block[l] == block[query.l]) {
            if (r == query.r) {
                return l < query.l;
            }
            return r < query.r;
        }
        return l < query.l;
    }
} q[MAXN];
set<int> lens;
int head[MAXN * 2], tail[MAXN * 2];
int val[MAXN * 500];
int nextL[MAXN * 500];
int nextR[MAXN * 500];
int num[MAXN];
int ans[MAXN];

inline int length(int pos) {
    return val[tail[pos]] - val[head[pos]];
}

inline void remove(int pos) {
    if (head[pos] != -1 && head[pos] != tail[pos]) {
        int len = length(pos);
        if (--num[len] == 0) {
            lens.erase(len);
        }
    }
}

inline void insert(int pos) {
    if (head[pos] != -1 && head[pos] != tail[pos]) {
        int len = length(pos);
        if (++num[len] == 1) {
            lens.insert(len);
        }
    }
}

int readInt() {
    char ch;
    bool negative = false;
    while (ch = getchar()) {
        if ('0' <= ch && ch <= '9') {
            break;
        }
        if (ch == '-') {
            negative = true;
        }
    }
    int num = ch - '0';
    while (ch = getchar()) {
        if ('0' <= ch && ch <= '9') {
            num = num * 10 + ch - '0';
        } else {
            break;
        }
    }
    return negative ? -num : num;
}

int main() {
    n = readInt();
    m = readInt();
    int len = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        s[i] = readInt();
        s[i] += s[i - 1];
        block[i] = (i - 1) / len;
    }
    for (int i = 0; i < m; ++i) {
        q[i].idx = i;
        q[i].l = readInt();
        q[i].r = readInt();
    }
    sort(q, q + m);
    int l = 0, r = -1;
    int idx = 0;
    memset(head, -1, sizeof(head));
    memset(tail, -1, sizeof(tail));
    for (int i = 0; i < m; ++i) {
        --q[i].l;
        for (; r < q[i].r; ++r) {
            int pos = s[r + 1] + SHIFT;
            remove(pos);
            val[idx] = r + 1;
            if (tail[pos] == -1) {
                nextL[idx] = nextR[idx] = -1;
                head[pos] = tail[pos] = idx;
            } else {
                nextL[idx] = tail[pos];
                nextR[tail[pos]] = idx;
                nextR[idx] = -1;
                tail[pos] = idx;
            }
            ++idx;
            insert(pos);
        }
        for (; r > q[i].r; --r) {
            int pos = s[r] + SHIFT;
            remove(pos);
            if (head[pos] == tail[pos]) {
                head[pos] = tail[pos] = -1;
            } else {
                tail[pos] = nextL[tail[pos]];
            }
            insert(pos);
        }
        for (; l < q[i].l; ++l) {
            int pos = s[l] + SHIFT;
            remove(pos);
            if (head[pos] == tail[pos]) {
                head[pos] = tail[pos] = -1;
            } else {
                head[pos] = nextR[head[pos]];
            }
            insert(pos);
        }
        for (; l > q[i].l; --l) {
            int pos = s[l - 1] + SHIFT;
            remove(pos);
            val[idx] = l - 1;
            if (head[pos] == -1) {
                nextL[idx] = nextR[idx] = -1;
                head[pos] = tail[pos] = idx;
            } else {
                nextR[idx] = head[pos];
                nextL[head[pos]] = idx;
                nextL[idx] = -1;
                head[pos] = idx;
            }
            ++idx;
            insert(pos);
        }
        if (lens.size() > 0) {
            ans[q[i].idx] = *lens.rbegin();
        }
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
