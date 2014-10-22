#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

struct Node {
    int type, time, num;
    bool operator <(const Node &node) const {
        if (time == node.time) {
            return type < node.type;
        }
        return time < node.time;
    }
} node[MAXN * 2];

int main() {
    int T, n;
    int a, b, c;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        set<int> values;
        map<int, int> index;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &a, &b, &c);
            node[i].type = 0;
            node[i].time = a;
            node[i].num = c;
            node[i + n].type = 1;
            node[i + n].time = b;
            node[i + n].num = c;
        }
        sort(node, node + n + n);
        int ans = 0;
        int num = 0;
        for (int i = 0; i < n + n; ++i) {
            if (node[i].type == 0) {
                num += node[i].num;
                ans = max(ans, num);
            } else {
                num -= node[i].num;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
