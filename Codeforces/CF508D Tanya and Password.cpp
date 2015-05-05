#include <bits/stdc++.h>
using namespace std;
const int MAXN = 65536;

int n;

struct Edge {
    int v, next;
};
int head[MAXN];
vector<Edge> edge;

int in[MAXN], out[MAXN];
string ans;

void init() {
    edge.clear();
    memset(head, -1, sizeof(head));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
}

inline void addEdge(int u, int v) {
    int edgeNum = (int)edge.size();
    edge.push_back({v, head[u]});
    head[u] = edgeNum;
}

void dfs(int u) {
    for (int i = head[u]; i != -1; i = head[u]) {
        head[u] = edge[i].next;
        int v = edge[i].v;
        dfs(v);
        ans += (char)(v & ((1 << 7) - 1));
    }
}

int main() {
    int n;
    char s[10];
    while (~scanf("%d", &n)) {
        init();
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            int a = s[0], b = s[1], c = s[2];
            int u = (a << 7) | b;
            int v = (b << 7) | c;
            addEdge(u, v);
            ++in[v];
            ++out[u];
        }
        bool possible = true;
        int start = -1, end = -1;
        for (int i = 0; i < MAXN; ++i) {
            if (abs(in[i] - out[i]) > 1) {
                possible = false;
                break;
            }
            if (out[i] - in[i] == 1) {
                if (start == -1) {
                    start = i;
                } else {
                    break;
                }
            } else if (in[i] - out[i] == 1) {
                if (end == -1) {
                    end = i;
                } else {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) {
            if (start == -1) {
                for (int i = 0; i < MAXN; ++i) {
                    if (out[i]) {
                        start = i;
                        break;
                    }
                }
            }
            ans = string();
            dfs(start);
            ans += (char)(start & ((1 << 7) - 1));
            ans += (char)(start >> 7);
            for (int i = 0; i < MAXN; ++i) {
                if (head[i] != -1) {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) {
            puts("YES");
            for (int i = ans.length() - 1; i >= 0; --i) {
                putchar(ans[i]);
            }
            putchar('\n');
        } else {
            puts("NO");
        }
    }
    return 0;
}
