#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
const int MOD = 1000000007;

vector<int> love[MAXN];
vector<int> hate[MAXN];

char color[MAXN];

void find(int u, char c) {
    if (color[u] > 0 && color[u] != c) {
        puts("0");
        exit(0);
    }
    if (color[u] == 0) {
        color[u] = c;
        for (int i = 0; i < (int)love[u].size(); ++i) {
            find(love[u][i], c);
        }
        for (int i = 0; i < (int)hate[u].size(); ++i) {
            find(hate[u][i], 3 - c);
        }
    }
}

int main() {
	int n, m;
    int u, v, w;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        if (w == 1) {
            love[u].push_back(v);
            love[v].push_back(u);
        } else {
            hate[u].push_back(v);
            hate[v].push_back(u);
        }
    }
    int ans = 500000004;
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            find(i, 1);
            ans = (ans + ans) % MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}
