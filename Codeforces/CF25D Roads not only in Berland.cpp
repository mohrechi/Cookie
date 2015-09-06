#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;

int n, u[MAXN], v[MAXN], parent[MAXN];

void init() {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
}

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void combine(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    scanf("%d", &n);
    init();
    vector<int> rm;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        if (find(u[i]) != find(v[i])) {
            combine(u[i], v[i]);
        } else {
            rm.push_back(i);
        }
    }
    vector<pair<pair<int, int>, pair<int, int>>> ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (find(i) != find(j)) {
                int idx = *rm.rbegin();
                rm.pop_back();
                ans.push_back({{u[idx], v[idx]}, {i, j}});
                combine(i, j);
            }
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto& a : ans) {
        printf("%d %d %d %d\n", a.first.first, a.first.second, a.second.first, a.second.second);
    }
    return 0;
}
