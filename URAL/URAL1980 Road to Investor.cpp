#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10;
const int MAXM = 10000 + 10;

int n, m;
double T;
struct Edge {
    int u, v, next;
    double speed, length;
} edge[MAXM * 2];
int head[MAXN], edgeNum;

inline void initGraph() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(const int &u, const int &v, const double &speed, const double &length) {
    edge[edgeNum].u = u;
    edge[edgeNum].v = v;
    edge[edgeNum].speed = speed;
    edge[edgeNum].length = length;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(const int &u, const int &v, const double &speed, const double &length) {
    addEdgeSub(u, v, speed, length);
    addEdgeSub(v, u, speed, length);
}

int q[MAXN], from[MAXN];
bool visit[MAXN];
double minTime[MAXN];

double spfa(const double &exceed) {
    int front = 0, rear = 1;
    for (int i = 1; i <= n; ++i) {
        minTime[i] = 1e100;
    }
    memset(visit, false, sizeof(visit));
    visit[1] = true;
    minTime[1] = 0;
    q[0] = 1;
    while (front != rear) {
        int u = q[front];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int& v = edge[i].v;
            double& speed = edge[i].speed;
            double& length = edge[i].length;
            if (minTime[v] > minTime[u] + length / (speed + exceed)) {
                minTime[v] = minTime[u] + length / (speed + exceed);
                from[v] = i;
                if (!visit[v]) {
                    visit[v] = true;
                    q[rear] = v;
                    if (++rear >= MAXN) {
                        rear = 0;
                    }
                }
            }
        }
        visit[u] = false;
        if (++front >= MAXN) {
            front = 0;
        }
    }
    return minTime[n];
}

int stk[MAXN], top;

int main() {
    int a, b;
    double s, l;
    while (cin >> n >> m) {
        initGraph();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%lf%lf", &a, &b, &s, &l);
            addEdge(a, b, s, l);
        }
        cin >> T;
        double l = 0.0, r = 1e8;
        while (r - l > 1e-7) {
            double mid = (l + r) * 0.5;
            if (spfa(mid) <= T) {
                r = mid;
            } else {
                l = mid;
            }
        }
        top = 0;
        int temp = n;
        while (temp != 1) {
            stk[top++] = (from[temp] >> 1) + 1;
            temp = edge[from[temp]].u;
        }
        printf("%.6f %d\n", (l + r) * 0.5, top);
        for (int i = top - 1; i >= 0; --i) {
            if (i != top - 1) {
                putchar(' ');
            }
            printf("%d", stk[i]);
        }
        putchar('\n');
    }
    return 0;
}
