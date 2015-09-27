#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m, s;
struct Bug {
    int a, idx;
    bool operator <(const Bug &bug) const {
        return a > bug.a;
    }
} bug[MAXN];
struct Stu {
    int b, c, idx;
    bool operator <(const Stu &stu) const {
        return b > stu.b;
    }
} stu[MAXN];
int divide[MAXN];

bool solve(int day) {
    set<pair<int, int>> ss;
    long long total = 0;
    for (int i = 1, j = 1; i <= m;) {
        while (j <= n && stu[j].b >= bug[i].a) {
            ss.insert({stu[j].c, j});
            ++j;
        }
        if (ss.size() == 0) {
            return false;
        }
        auto it = ss.begin();
        total += stu[it->second].c;
        for (int k = 0; k < day && i <= m; ++k, ++i) {
            divide[bug[i].idx] = stu[it->second].idx;
        }
        ss.erase(it);
    }
    return total <= s;
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; ++i) {
        bug[i].idx = i;
        scanf("%d", &bug[i].a);
    }
    sort(bug + 1, bug + 1 + m);
    for (int i = 1; i <= n; ++i) {
        stu[i].idx = i;
        scanf("%d", &stu[i].b);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &stu[i].c);
    }
    sort(stu + 1, stu + 1 + n);
    int ans = -1;
    int l = 1, r = m;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (solve(mid)) {
            r = mid - 1;
            if (ans == -1 || ans > mid) {
                ans = mid;
            }
        } else {
            l = mid + 1;
        }
    }
    if (ans != -1) {
        puts("YES");
        solve(ans);
        for (int i = 1; i <= m; ++i) {
            printf("%d ", divide[i]);
        }
        putchar('\n');
    } else {
        puts("NO");
    }
    return 0;
}
