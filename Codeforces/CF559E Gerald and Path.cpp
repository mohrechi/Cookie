#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int n;
struct Node {
    int a, l;
    bool operator <(const Node &node) const {
        if (a == node.a) {
            return l < node.l;
        }
        return a < node.a;
    }
} node[MAXN];
set<pair<int, int>, greater<pair<int, int>>> segs[MAXN][MAXN];

set<int> posSet;
map<int, int> idx;
int pos[MAXN * 3], posNum;
int dp[MAXN][MAXN * 3];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &node[i].a, &node[i].l);
        posSet.insert(node[i].a);
        posSet.insert(node[i].a - node[i].l);
        posSet.insert(node[i].a + node[i].l);
    }
    posNum = 0;
    for (auto v : posSet) {
        idx[v] = posNum;
        pos[posNum++] = v;
    }
    sort(node + 1, node + 1 + n);
    for (int i = 1; i <= n; ++i) {
        segs[i][i].insert({node[i].a - node[i].l, node[i].a});
        segs[i][i].insert({node[i].a, node[i].a + node[i].l});
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            for (int d = i; d < j; ++d) {
                for (auto& seg1 : segs[i][d]) {
                    for (auto& seg2 : segs[d + 1][j]) {
                        if (seg1.second >= seg2.first) {
                            segs[i][j].insert({min(seg1.first, seg2.first), max(seg1.second, seg2.second)});
                        }
                    }
                }
            }
            pair<int, int> last = {0, 0};
            for (auto seg = segs[i][j].begin(); seg != segs[i][j].end(); ++seg) {
                if (last.first <= seg->first && seg->second <= last.second) {
                    seg = segs[i][j].erase(seg);
                    --seg;
                } else {
                    last = *seg;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < posNum; ++j) {
            if (j) {
                dp[i][j] = -1;
            }
            for (int k = 0; k < i; ++k) {
                for (auto& seg : segs[k + 1][i]) {
                    if (seg.second <= pos[j]) {
                        dp[i][j] = max(dp[i][j], dp[k][idx[seg.first]] + (seg.second - seg.first));
                    }
                }
            }
        }
    }
    printf("%d\n", dp[n][posNum - 1]);
    return 0;
}
