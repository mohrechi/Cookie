#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
const int MAXM = 200000 + 10;

int n, m;
int degree[MAXN];
vector<int> ans;
multiset<int> edge[MAXN];

void dfs(int u) {
    while (!edge[u].empty()) {
        int v = *edge[u].begin();
        edge[u].erase(edge[u].begin());
        edge[v].erase(edge[v].find(u));
        dfs(v);
    }
    ans.push_back(u);
}

int main() {
    int u, v;
    int edgeNum = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        edge[u].insert(v);
        edge[v].insert(u);
        ++degree[u];
        ++degree[v];
        ++edgeNum;
    }
    int last = 0;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] & 1) {
            if (last == 0) {
                last = i;
            } else {
                edge[last].insert(i);
                edge[i].insert(last);
                ++edgeNum;
                last = 0;
            }
        }
    }
    if (last) {
        ++edgeNum;
    }
    if (edgeNum & 1) {
        ++edgeNum;
    }
    cout << edgeNum << endl;
    dfs(1);
    for (int i = 1; i < ans.size(); ++i) {
        if (i & 1) {
            cout << ans[i] << " " << ans[i - 1] << endl;
        } else {
            cout << ans[i - 1] << " " << ans[i] << endl;
        }
    }
    if ((ans.size() & 1) == 0) {
        cout << "1 1" << endl;
    }
    return 0;
}
