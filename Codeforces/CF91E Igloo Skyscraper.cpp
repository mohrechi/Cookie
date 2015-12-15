#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 5;
constexpr int MAXQ = 1e5 + 5;
constexpr int MAXM = sqrt(MAXN) + 5;
constexpr int MAXT = 1e6 + 5;

int n, m, q;
int a[MAXN], b[MAXN];

struct ChangeNode {
    int time, pos;
    bool operator <(const ChangeNode& node) const {
        return time < node.time;
    }
};

struct QueryNode {
    int index;
    int l, r, t;
    bool operator <(const QueryNode& node) const {
        if (t == node.t) {
            return index < node.index;
        }
        return t < node.t;
    }
} query[MAXN];

int ans[MAXN];
long long maxHeights[MAXQ];

void checkInterval(int i, int l, int r) {
    for (int j = l; j <= r; ++j) {
        long long height = a[j] + (long long)b[j] * query[i].t;
        if (height > maxHeights[i]) {
            maxHeights[i] = height;
            ans[query[i].index] = j;
        }
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 0; i < q; ++i) {
        query[i].index = i;
        scanf("%d%d%d", &query[i].l, &query[i].r, &query[i].t);
    }
    sort(query, query + q);
    m = sqrt(n);
    for (int i = 1; i <= n; i += m) {
        int maxHeight = -1, pos;
        for (int j = i; j < i + m; ++j) {
            if (a[j] > maxHeight) {
                maxHeight = a[j];
                pos = j;
            }
        }
        set<ChangeNode> changes;
        for (int j = i; j < i + m; ++j) {
            int left = 0, right = MAXT;
            for (int k = i; k < i + m; ++k) {
                if (j == k) {
                    continue;
                }
                if (b[j] == b[k]) {
                    if (a[j] < a[k]) {
                        right = -1;
                        break;
                    }
                } else if (b[j] > b[k]) {
                    left = max(left, (a[k] - a[j]) / (b[j] - b[k]) + ((a[k] - a[j]) % (b[j] - b[k]) != 0));
                } else {
                    if (a[j] < a[k]) {
                        right = -1;
                        break;
                    }
                    right = min(right, (a[k] - a[j]) / (b[j] - b[k]));
                }
                if (left > right) {
                    break;
                }
            }
            if (left <= right && left < MAXT) {
                changes.insert({left, j});
            }
        }
        int index = (i - 1) / m;
        for (int j = 0; j < q; ++j) {
            while (changes.size() > 0 && changes.begin()->time <= query[j].t) {
                pos = changes.begin()->pos;
                changes.erase(changes.begin());
            }
            int l = (query[j].l - 1) / m;
            int r = (query[j].r - 1) / m;
            if (l < index && index < r) {
                long long height = a[pos] + (long long)b[pos] * query[j].t;
                if (height > maxHeights[j]) {
                    maxHeights[j] = height;
                    ans[query[j].index] = pos;
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int l = (query[i].l - 1) / m;
        int r = (query[i].r - 1) / m;
        if (l == r) {
            checkInterval(i, query[i].l, query[i].r);
        } else {
            checkInterval(i, query[i].l, (l + 1) * m);
            checkInterval(i, r * m + 1, query[i].r);
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
