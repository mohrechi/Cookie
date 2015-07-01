#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXD = 200 + 10;

int n;
struct Node {
    int l, d;
    bool operator <(const Node &node) const {
        return l < node.l;
    }
} node[MAXN];
int sumR[MAXN], cnt[MAXD];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &node[i].l);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &node[i].d);
    }
    sort(node, node + n);
    for (int i = n - 1; i >= 0; --i) {
        sumR[i] += node[i].d + sumR[i + 1];
    }
    int left = 0;
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        if (i == n or node[i].l != node[left].l) {
            int score = sumR[i];
            int num = i - left;
            int rem = i - num * 2 + 1;
            if (num <= i / 2) {
                for (int j = 0; j < MAXD; ++j) {
                    if (cnt[j]) {
                        if (rem > cnt[j]) {
                            score += j * cnt[j];
                            rem -= cnt[j];
                        } else {
                            score += j * rem;
                            rem = 0;
                            break;
                        }
                    }
                }
            }
            if (rem <= 0) {
                ans = min(ans, score);
            }
            for (int j = left; j < i; ++j) {
                ++cnt[node[j].d];
            }
            left = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
