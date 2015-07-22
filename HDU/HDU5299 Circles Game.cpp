#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 20000 + 10;

struct Circle {
    int x, y, r;
    inline void input() {
        scanf("%d%d%d", &x, &y, &r);
    }
    bool operator <(const Circle &cir) const {
        return r < cir.r;
    }
} circle[MAXN];
int in[MAXN];

pair<int, int> removeList[MAXN];

struct Edge {
    int v, next;
} edge[MAXN];
int head[MAXN], edgeNum;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v) {
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

int sg(int u) {
    int mex = 0;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        mex ^= sg(edge[i].v) + 1;
    }
    return mex;
}

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        set< pair<int, int> > axis;
        for (int i = 0; i < n; ++i) {
            circle[i].input();
        }
        sort(circle, circle + n);
        for (int i = 0; i < n; ++i) {
            axis.insert(pair<int, int>(circle[i].x, i));
        }
        clearEdge();
        memset(in, 0, sizeof(in));
        for (int i = 0; i < n; ++i) {
            int removeNum = 0;
            set< pair<int, int> >::iterator lower = axis.lower_bound(pair<int, int>(circle[i].x - circle[i].r, 0));
            set< pair<int, int> >::iterator upper = axis.upper_bound(pair<int, int>(circle[i].x + circle[i].r, n));
            for (; lower != upper; ++lower) {
                int j = lower->second;
                if (i > j) {
                    int dx = circle[i].x - circle[j].x;
                    int dy = circle[i].y - circle[j].y;
                    if (circle[i].r * circle[i].r > dx * dx + dy * dy) {
                        addEdge(i, j);
                        ++in[j];
                        removeList[removeNum++] = *lower;
                    }
                }
            }
            for (int i = 0; i < removeNum; ++i) {
                axis.erase(removeList[i]);
            }
        }
        int mex = 0;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                mex ^= sg(i) + 1;
            }
        }
        puts(mex ? "Alice" : "Bob");
    }
    return 0;
}
