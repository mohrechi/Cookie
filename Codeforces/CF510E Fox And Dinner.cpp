#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 10;
const int MAXP = 2e4 + 10;

bool isPrime[MAXP];

void initPrime() {
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 4; i < MAXP; i += 2) {
        isPrime[i] = false;
    }
    for (int i = 3; i < MAXP; i += 2) {
        for (int j = i + i; j < MAXP; j += i) {
            isPrime[j] = false;
        }
    }
}

int n, a[MAXN];
int odd[MAXN], oddNum;
int even[MAXN], evenNum;
int src, dst;

struct Edge {
    int v, flow, next;
} edge[MAXN * MAXN];
int head[MAXN], edgeNum;

inline void initGraph() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(const int &u, const int &v, const int &flow) {
    edge[edgeNum].v = v;
    edge[edgeNum].flow = flow;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(const int &u, const int &v, const int &flow) {
    addEdgeSub(u, v, flow);
    addEdgeSub(v, u, 0);
}

int que[MAXN], depth[MAXN];

bool bfs() {
    int front = 0, rear = 1;
    memset(depth, -1, sizeof(depth));
    que[0] = src;
    depth[src] = 0;
    while (front < rear) {
        int u = que[front++];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            if (edge[i].flow) {
                int v = edge[i].v;
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    que[rear++] = v;
                }
            }
        }
    }
    return depth[dst] >= 0;
}

int dinic(int u, int sum) {
    if (u == dst) {
        return sum;
    }
    int temp = sum;
    for (int i = head[u]; i != -1 && sum; i = edge[i].next) {
        if (edge[i].flow) {
            int v = edge[i].v;
            if (depth[v] == depth[u] + 1) {
                int flow = dinic(v, min(sum, edge[i].flow));
                edge[i].flow -= flow;
                edge[i ^ 1].flow += flow;
                sum -= flow;
            }
        }
    }
    return temp - sum;
}

int maxFlow() {
    int ret = 0;
    while (bfs()) {
        ret += dinic(src, 0x3f3f3f3f);
    }
    return ret;
}

int main() {
    initPrime();
    while (cin >> n) {
        oddNum = 0;
        evenNum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] & 1) {
                odd[oddNum++] = i;
            } else {
                even[evenNum++] = i;
            }
        }
        bool possible = evenNum == oddNum;
        if (possible) {
            initGraph();
            src = n;
            dst = n + 1;
            for (int i = 0; i < oddNum; ++i) {
                addEdge(src, i, 2);
            }
            for (int i = 0; i < evenNum; ++i) {
                addEdge(oddNum + i, dst, 2);
            }
            for (int i = 0; i < oddNum; ++i) {
                for (int j = 0; j < evenNum; ++j) {
                    if (isPrime[a[odd[i]] + a[even[j]]]) {
                        addEdge(i, oddNum + j, 1);
                    }
                }
            }
            possible = maxFlow() == n;
        }
        vector<vector<int>> tables;
        if (possible) {
            vector<vector<int>> connect(n + 1);
            for (int u = 0; u < oddNum; ++u) {
                for (int i = head[u]; i != -1; i = edge[i].next) {
                    int v = edge[i].v;
                    if (edge[i].flow == 0 && v != src) {
                        connect[odd[u]].push_back(even[v - oddNum]);
                        connect[even[v - oddNum]].push_back(odd[u]);
                    }
                }
            }
            memset(depth, -1, sizeof(depth));
            for (int i = 1; i <= n; ++i) {
                if (depth[i] == -1) {
                    vector<int> table;
                    int last = -1, u = i;
                    bool circle = true;
                    while (circle) {
                        circle = false;
                        depth[u] = 0;
                        table.push_back(u);
                        for (auto v : connect[u]) {
                            if (v != last && depth[v] == -1) {
                                last = u;
                                u = v;
                                circle = true;
                            }
                        }
                    }
                    if ((int)table.size() < 3) {
                        possible = false;
                    }
                    tables.push_back(table);
                }
            }
        }
        if (possible) {
            cout << tables.size() << endl;
            for (auto table : tables) {
                cout << table.size();
                for (auto fox : table) {
                    cout << " " << fox;
                }
                cout << endl;
            }
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
