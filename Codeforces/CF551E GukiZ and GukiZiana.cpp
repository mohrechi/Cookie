#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
const int MAXM = 750;

int n, m, k, q;

struct Position {
    int idx;
    long long val;
    bool operator <(const Position &pos) const {
        if (val == pos.val) {
            return idx < pos.idx;
        }
        return val < pos.val;
    }
};

struct Interval {
    int num;
    long long inc, org[MAXM];
    Position pos[MAXM];
    inline void sort() {
        ::sort(pos, pos + num);
    }
    inline void update(int l, int r, long long x) {
        for (int i = 0; i < num; ++i) {
            org[i] += inc;
            if (l <= i and i <= r) {
                org[i] += x;
            }
            pos[i].idx = i;
            pos[i].val = org[i];
        }
        inc = 0;
        sort();
    }
    inline int findLeft(long long y) {
        int l = 0, r = num;
        int ret = num;
        y -= inc;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pos[mid].val >= y) {
                r = mid - 1;
                if (pos[mid].val == y) {
                    ret = min(ret, mid);
                }
            } else {
                l = mid + 1;
            }
        }
        if (ret == num) {
            return -1;
        }
        return pos[ret].idx;
    }
    inline int findRight(long long y) {
        int l = 0, r = num;
        int ret = -1;
        y -= inc;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pos[mid].val <= y) {
                l = mid + 1;
                if (pos[mid].val == y) {
                    ret = max(ret, mid);
                }
            } else {
                r = mid - 1;
            }
        }
        if (ret == -1) {
            return -1;
        }
        return pos[ret].idx;
    }
} inter[MAXM];

int main() {
    int a, l, r, x, y;
    scanf("%d%d", &n, &q);
    m = sqrt((double)n) + 1;
    k = -1;
    for (int i = 0, j = m; i < n; ++i, ++j) {
        if (j == m) {
            ++k;
            j = 0;
            inter[k].inc = 0;
            inter[k].num = 0;
        }
        scanf("%d", &a);
        inter[k].org[j] = a;
        inter[k].pos[j].idx = j;
        inter[k].pos[j].val = a;
        ++inter[k].num;
    }
    for (int i = 0; i <= k; ++i) {
        inter[i].sort();
    }
    while (q--) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d%d%d", &l, &r, &x);
            --l, --r;
            int lb = l / m, li = l % m;
            int rb = r / m, ri = r % m;
            if (lb == rb) {
                inter[lb].update(li, ri, x);
            } else {
                inter[lb].update(li, inter[lb].num - 1, x);
                inter[rb].update(0, ri, x);
                for (int i = lb + 1; i <= rb - 1; ++i) {
                    inter[i].inc += x;
                }
            }
        } else {
            scanf("%d", &y);
            int right = -1;
            for (int i = k; i >= 0; --i) {
                right = inter[i].findRight(y);
                if (right != -1) {
                    right += i * m;
                    break;
                }
            }
            if (right == -1) {
                puts("-1");
                continue;
            }
            int left = -1;
            for (int i = 0; i <= k; ++i) {
                left = inter[i].findLeft(y);
                if (left != -1) {
                    left += i * m;
                    break;
                }
            }
            printf("%d\n", right - left);
        }
    }
    return 0;
}
