#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
const int MOD = 1e9 + 7;

int n, m;
int want[MAXN];
int wanted[MAXN][2];

int parent[MAXN];
bool visit[MAXN];

inline void initSet() {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
}

int findSet(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = findSet(parent[x]);
}

inline void combineSet(int x, int y) {
    parent[findSet(x)] = findSet(y);
}

vector<vector<int>> chains;

long long factorial(const int &k) {
    long long ret = 1;
    for (int i = 1; i <= k; ++i) {
        ret = ret * i % MOD;
    }
    return ret;
}

long long power2(const int &k) {
    long long ret = 1;
    for (int i = 1; i <= k; ++i) {
        ret = ret * 2 % MOD;
    }
    return ret;
}

int main() {
    cin >> n >> m;
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }
    initSet();
    memset(wanted, -1, sizeof(wanted));
    for (int i = 1; i <= m; ++i) {
        cin >> want[i];
        combineSet(i, want[i]);
        if (wanted[want[i]][0] == -1) {
            wanted[want[i]][0] = i;
        } else if (wanted[want[i]][1] == -1) {
            wanted[want[i]][1] = i;
        } else {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (wanted[i][1] != -1) {
            if (i <= m && want[i] != wanted[i][0] && want[i] != wanted[i][1]) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    memset(visit, false, sizeof(visit));
    chains.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            int color = findSet(i);
            vector<int> chain;
            for (int j = i; j <= n; ++j) {
                if (findSet(j) == color) {
                    chain.push_back(j);
                    visit[j] = true;
                }
            }
            chains.push_back(chain);
        }
    }
    bool isCycle;
    int multiNum = 0;
    for (auto chain : chains) {
        isCycle = true;
        for (auto people : chain) {
            if (wanted[people][1] != -1 || people > m) {
                isCycle = false;
                break;
            }
        }
        if (isCycle && chain.size() > 2 && n != chain.size()) {
            cout << 0 << endl;
            return 0;
        }
        if (chain.size() > 1) {
            ++multiNum;
        }
    }
    int k = chains.size();
    int l = chains[0].size();
    long long ans = factorial(k - 1) * power2(multiNum) % MOD;
    cout << ans << endl;
    return 0;
}
