#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;

int n, q, parent[MAXN];

void initUnion() {
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

struct Segments {
    int id, l, r;
    bool operator <(const Segments& seg) const {
        return l < seg.l;
    }
};

set<Segments> segs;

void initSegments() {
    for (int i = 1; i <= n + 1; ++i) {
        segs.insert({i, i, i});
    }
}

inline int query(int x) {
    auto it = segs.upper_bound({0, x, 0});
    return (--it)->id;
}

void update(int x, int y) {
    auto itL = segs.upper_bound({0, x, 0});
    auto itR = segs.upper_bound({0, y, 0});
    --itL;
    int id = itL->id;
    int l = itL->l;
    int r = itR->l - 1;
    while (itL != itR) {
        combine(itL->id, id);
        segs.erase(itL++);
    }
    segs.insert({id, l, r});
}

int main() {
    int type, x, y;
    scanf("%d%d", &n, &q);
    initUnion();
    initSegments();
    while (q--) {
        scanf("%d%d%d", &type, &x, &y);
        switch (type) {
        case 1:
            combine(query(x), query(y));
            break;
        case 2:
            update(x, y);
            break;
        case 3:
            puts(find(query(x)) == find(query(y)) ? "YES" : "NO");
            break;
        }
    }
    return 0;
}
