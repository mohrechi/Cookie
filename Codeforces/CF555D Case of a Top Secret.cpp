#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int n, m;
struct Node {
    int index, x;
    bool operator <(const Node &node) const {
        if (x == node.x) {
            return index < node.index;
        }
        return x < node.x;
    }
} node[MAXN];
map<int, int> pos;
int history[3], idx;

inline bool clearHistory() {
    idx = 0;
}

inline void addHistory(int x) {
    if (idx < 3) {
        history[idx++] = x;
    } else {
        for (int i = 0; i < 2; ++i) {
            history[i] = history[i + 1];
        }
        history[2] = x;
    }
}

inline bool isHistoryRepeating() {
    return idx == 3 and history[0] == history[2];
}

inline int getHistoryLength() {
    return abs(node[history[1]].x - node[history[2]].x) * 2;
}

int main() {
    int a, l;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        node[i].index = i;
        scanf("%d", &node[i].x);
    }
    sort(node + 1, node + 1 + n);
    for (int i = 1; i <= n; ++i) {
        pos[node[i].index] = i;
    }
    while (m--) {
        scanf("%d%d", &a, &l);
        a = pos[a];
        clearHistory();
        addHistory(a);
        bool toRight = true;
        bool failLeft = false;
        bool failRight = false;
        while (true) {
            if (failLeft and failRight) {
                break;
            }
            if (toRight) {
                int left = a + 1, right = n;
                int next = 0;
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (node[mid].x - node[a].x <= l) {
                        left = mid + 1;
                        next = max(next, mid);
                    } else {
                        right = mid - 1;
                    }
                }
                if (next == 0) {
                    failRight = true;
                } else {
                    addHistory(next);
                    failLeft = false;
                    failRight = false;
                    l -= node[next].x - node[a].x;
                    a = next;
                }
            } else {
                int left = 1, right = a - 1;
                int next = n + 1;
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (node[a].x - node[mid].x <= l) {
                        right = mid - 1;
                        next = min(next, mid);
                    } else {
                        left = mid + 1;
                    }
                }
                if (next == n + 1) {
                    failLeft = true;
                } else {
                    addHistory(next);
                    failLeft = false;
                    failRight = false;
                    l -= node[a].x - node[next].x;
                    a = next;
                }
            }
            if (isHistoryRepeating()) {
                l %= getHistoryLength();
                clearHistory();
            }
            toRight = not toRight;
        }
        printf("%d\n", node[a].index);
    }
    return 0;
}
