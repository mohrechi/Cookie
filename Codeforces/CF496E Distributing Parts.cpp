#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m;

struct Part {
    int idx, a, b;
    bool operator <(const Part &part) const {
        return a < part.a;
    }
} parts[MAXN];

struct Actor {
    int idx, c, d, k;
    bool operator <(const Actor &actor) const {
        return c < actor.c;
    }
} actors[MAXN];

int assignment[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        parts[i].idx = i;
        scanf("%d%d", &parts[i].a, &parts[i].b);
    }
    sort(parts + 1, parts + 1 + n);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        actors[i].idx = i;
        scanf("%d%d%d", &actors[i].c, &actors[i].d, &actors[i].k);
    }
    sort(actors + 1, actors + 1 + m);
    bool valid = true;
    set<pair<int, int>> available;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= m && actors[j].c <= parts[i].a) {
            available.insert({actors[j].d, j});
            ++j;
        }
        auto it = available.lower_bound({parts[i].b, 0});
        if (it == available.end()) {
            valid = false;
            break;
        }
        assignment[parts[i].idx] = actors[it->second].idx;
        if (--actors[it->second].k <= 0) {
            available.erase(it);
        }
    }
    if (valid) {
        puts("YES");
        for (int i = 1; i <= n; ++i) {
            printf("%d ", assignment[i]);
        }
        putchar('\n');
    } else {
        puts("NO");
    }
    return 0;
}
