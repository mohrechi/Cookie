#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int n;
struct Edge {
    int v, next;
} edge[MAXN];
int head[MAXN], edgeNum;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v) {
    edge[edgeNum] = {v, head[u]};
    head[u] = edgeNum++;
}

int dp[MAXN];

int initDp(int u) {
    dp[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        dp[u] = (long long)dp[u] * (initDp(v) + 1) % MOD;
    }
    return dp[u];
}

int ans[MAXN];

void calcNum(int u, int in) {
    ans[u] = (in + 1) % MOD;
    vector<int> idx;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        ans[u] = (long long)ans[u] * (dp[v] + 1) % MOD;
        idx.push_back(v);
    }
    vector<int> left(idx.size() + 1), right(idx.size() + 2);
    left[0] = 1;
    for (int i = 0; i < (int)idx.size(); ++i) {
        left[i + 1] = (long long)left[i] * (dp[idx[i]] + 1) % MOD;
    }
    right[idx.size() + 1] = 1;
    for (int i = (int)idx.size() - 1; i >= 0; --i) {
        right[i + 1] = (long long)right[i + 2] * (dp[idx[i]] + 1) % MOD;
    }
    for (int i = head[u], j = 1; i != -1; i = edge[i].next, ++j) {
        int v = edge[i].v;
        calcNum(v, (long long)left[j - 1] * right[j + 1] % MOD * (in + 1) % MOD);
    }
}

int main() {
    int p;
    ios::sync_with_stdio(false);
    cin >> n;
    clearEdge();
    for (int i = 2; i <= n; ++i) {
        cin >> p;
        addEdge(p, i);
    }
    initDp(1);
    calcNum(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
