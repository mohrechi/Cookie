#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int n, a, b;
int inNum, outNum;
int in[MAXN], out[MAXN];

struct Edge {
    int v, next;
} edge[MAXN * MAXN];
int head[MAXN], edgeNum;

inline void initGraph() {
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v) {
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

bool visit[MAXN];
int link[MAXN];

bool find(int u) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!visit[v]) {
            visit[v] = true;
            if (link[v] == -1 || find(link[v])) {
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int t, d;
    scanf("%d%d%d", &a, &b, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &t, &d);
        if (d == 0) {
            in[inNum++] = t;
        } else {
            out[outNum++] = t;
        }
    }
    if (inNum != outNum) {
        puts("Liar");
        return 0;
    }
    initGraph();
    for (int i = 0; i < inNum; ++i) {
        for (int j = 0; j < outNum; ++j) {
            int inter = out[j] - in[i];
            if (inter >= 0 && (inter <= b || inter >= a)) {
                addEdge(i, j);
            }
        }
    }
    bool liar = false;
    memset(link, -1, sizeof(link));
    for (int i = 0; i < inNum; ++i) {
        memset(visit, false, sizeof(visit));
        if (!find(i)) {
            liar = true;
            break;
        }
    }
    if (liar) {
        puts("Liar");
    } else {
        puts("No reason");
        for (int i = 0; i < outNum; ++i) {
            printf("%d %d\n", in[link[i]], out[i]);
        }
    }
    return 0;
}
